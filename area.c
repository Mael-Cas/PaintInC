//
// Created by maelc on 28/04/2023.
//
#include "area.h"
#include <stdio.h>
#include <stdlib.h>
#include "shape.h"

Area* create_area(unsigned int width, unsigned int height){
    Area* area = (Area*) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->nb_shape = 0;
    area->mat = (BOOL **) malloc(sizeof(BOOL) * height);
    for(int i=0; i<height; i++){
        area->mat[i] = (BOOL*) malloc(sizeof(BOOL)*width);
        for(int j=0; j<width; j++){
            area->mat[i][j] = 0;
        }
    }
    return area;
}

void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

void clear_area(Area* area){
    for(int i = 0; i < area->height; i++){
        for(int j = 0; j < area->width; j++){
            area->mat[i][j] = 0;
        }
    }
}


void erase_area(Area* area){
    for(int i = 0; i < area->nb_shape; i++){
        free(area->shapes[i]);
    }
    area->nb_shape = 0;
}


void delete_area(Area* area){
    for(int i = 0; i < area->height; i++){
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);
}




/*void draw_area(Area* area){
    Pixel** pixels;
    for (int i=0; i<area->nb_shape; i++){
        pixels = create_shape_to_pixel(area->shapes[i]);

    }
}*/

void print_area(Area* area){
    for (int i=0; i<area->width; i++){
        for (int j=0; j<area->height; j++){
            if (area->mat[i][j] == 0){
                printf(". ");
            } else{
                if (area->mat[i][j] == 1){
                    printf("# ");
                }
            }
            printf("\n");
        }
    }
}


Pixel *create_pixel(int px, int py){
    Pixel* p = (Pixel*)malloc(sizeof(Pixel));
    p->px = px;
    p->py = py;
    return p;
};

void delete_pixel(Pixel * pixel){
    free(pixel);
}

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels){
    Point * p = (Point*) shape->ptrShape;
    pixel = (Pixel**) malloc(sizeof(Pixel*));
    pixel[0] = create_pixel(p->x, p->y);
    *nb_pixels = 1;
}
