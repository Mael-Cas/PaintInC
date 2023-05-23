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
    area->mat = (BOOL **) malloc(sizeof(BOOL*) * height);
    for(int i=0; i<height; i++){
        area->mat[i] = (BOOL*) malloc(width * sizeof(BOOL));
    }
    for (int i=0; i<height; i++){
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

void remove_shape_to_area(Area* area, Shape* shape){
    int cpt = 0;
    int bo = 0;
    for (int i=0; i<area->nb_shape; i++){
        if (area->shapes[i]->id == shape->id){
            for (int j=i; j < area->nb_shape; j++){
                if (j == area->nb_shape - 1){
                    free(area->shapes[j]);
                } else{
                    area->shapes[j] = area->shapes[j+1];
                }
            }
        }
    }
    area->nb_shape--;
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




void draw_area(Area* area){
    Pixel** pixels;
    int height = area->height;
    int width = area->width;
    printf("Nombre de formes : %d\n", area->nb_shape);
    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            area->mat[i][j] = 0;
        }
    }
    for (int i=0; i<area->nb_shape; i++){
        int *nb_pixels;
        *nb_pixels = 0;
        pixels = create_shape_to_pixel(area->shapes[i], nb_pixels);
        int px=0, py=0;
        for (int j=0; j < *nb_pixels; j++){
            px = pixels[j]->px;
            py = pixels[j]->py;
            area->mat[px][py] = 1;
        }
    }
}

void print_area(Area* area){
    for (int i=0; i<area->height; i++){
        for (int j=0; j<area->width; j++){
            if (area->mat[i][j] == 1){
                printf("# ");
            } else{
                printf(". ");
            }
        }
        printf("\n");
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

void pixel_point(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Point * p = (Point*) shape->ptrShape;
    *pixel = (Pixel**) malloc(sizeof(Pixel*));
    *pixel[(*nb_pixels)++] = create_pixel(p->x, p->y);
}

void pixel_ligne(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Line * l = (Line*) shape->ptrShape;
    Point pA, pB;
    int temp;
    if (l->p1.y <= l->p2.y){
        pA = l->p1;
        temp = pA.x;
        pA.x = pA.y;
        pA.y = temp;
        pB = l->p2;
        temp = pB.x;
        pB.x = pB.y;
        pB.y = temp;
    } else{
        pA = l->p2;
        temp = pA.x;
        pA.x = pA.y;
        pA.y = temp;
        pB = l->p1;
        temp = pB.x;
        pB.x = pB.y;
        pB.y = temp;
    }
    int dx = pB.x - pA.x;
    int dy = pB.y - pA.y;
    int dmin, dmax;

    if (dx >= abs(dy)){
        dmax = dx;
        dmin = abs(dy);
    } else{
        dmax = abs(dy);
        dmin = dx;
    }
    int nbSeg = dmin + 1;
    int nbPix = (dmax + 1)/(dmin + 1);
    int* tabSeg = (int *) malloc(nbSeg * sizeof(int));
    for (int i=0; i<nbSeg; i++){
        tabSeg[i] = nbPix;
    }
    int pixRes = (dmax + 1) % (dmin + 1);
    int *cumuls = (int *)malloc(nbSeg*sizeof(int));
    cumuls[0]=0;
    for (int i = 1; i < nbSeg;i++)
    {
        cumuls[i] = ((i+1)*pixRes)%(dmin+1) < ((i*pixRes)%(dmin+1));
        tabSeg[i] = tabSeg[i]+cumuls[i];
    }

    int nbPixTot = nbSeg*nbPix + pixRes;
    int taille;
    if (*nb_pixels != 0){
        taille = ((*nb_pixels) + nbPixTot) * sizeof(Pixel*);
        *pixel = realloc(*pixel, taille);
    } else{
        *pixel = (Pixel **) malloc(nbPixTot * sizeof(Pixel *));
    }

    int x=pA.x, y=pA.y;
    int cpt = 1;
    if (dy < 0){
        if (dx > abs(dy)){
            tabSeg[0] -= 1;
            (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
            for (int i=0; i<nbSeg; i++){
                for (int j=0; j<tabSeg[i]; j++){
                    x += 1;
                    (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
                    cpt += 1;
                }
                y -= 1;
            }
        } else{
            tabSeg[0] -= 1;
            (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
            for (int i=0; i<nbSeg; i++){
                for (int j=0; j<tabSeg[i]; j++){
                    y -= 1;
                    (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
                    cpt += 1;


                }
                x += 1;
            }
        }
    } else{
        if (dx > abs(dy)){
            tabSeg[0] -= 1;
            (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
            for (int i=0; i<nbSeg; i++){
                for (int j=0; j<tabSeg[i]; j++){
                    x += 1;
                    (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
                    cpt += 1;
                }
                y += 1;
            }
        } else{
            tabSeg[0] -= 1;
            (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
            for (int i=0; i<nbSeg; i++){
                for (int j=0; j<tabSeg[i]; j++){
                    y += 1;
                    (*pixel)[(*nb_pixels)++] = create_pixel(x, y);
                    cpt += 1;
                }
                x += 1;
            }
        }
    }
}

void pixel_circle(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Circle * c = shape->ptrShape;
    int x = 0;
    int y = c->radius;
    int d = y-1;
    Pixel * px=NULL;
    *pixel = (Pixel**) malloc(8*sizeof(Pixel*));
    BOOL first = 1;
    int taille = 8* sizeof(Pixel*);
    while (y >= x){
        if (!first){
            taille += 8* sizeof(Pixel*);
            *pixel = realloc(*pixel, taille);
        }

        px = create_pixel(c->center.x + x, c->center.y + y);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x + y, c->center.y + x);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x - x, c->center.y + y);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x - y, c->center.y + x);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x + x, c->center.y - y);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x + y, c->center.y - x);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x - x, c->center.y - y);
        (*pixel)[(*nb_pixels)++] = px;

        px = create_pixel(c->center.x - y, c->center.y - x);
        (*pixel)[(*nb_pixels)++] = px;


        if (d >= 2*x){
            d -= 2*x + 1;
            x++;
        }
        else if (d < 2*(c->radius-y))
        {
            d+= 2*y-1;
            y--;
        }
        else
        {
            d+= 2*(y-x-1);
            y--;
            x++;
        }
        first = 0;
    }
}

void pixel_square(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Square * s = shape->ptrShape;
    Point p1 = s->top;
    Point p2 = s->top;
    p2.y += s->length;
    Point p3 = s->top;
    p3.x += s->length;
    p3.y += s->length;
    Point p4 = s->top;
    p4.x += s->length;
    Shape *l1 = createLineShape(p1.x, p1.y, p2.x, p2.y);
    pixel_ligne(l1, pixel, nb_pixels);
    Shape *l2 = createLineShape(p2.x, p2.y, p3.x, p3.y);
    pixel_ligne(l2, pixel, nb_pixels);
    Shape *l3 = createLineShape(p3.x, p3.y, p4.x, p4.y);
    pixel_ligne(l3, pixel, nb_pixels);
    Shape *l4 = createLineShape(p4.x, p4.y, p1.x, p1.y);
    pixel_ligne(l4, pixel, nb_pixels);

}


void pixel_rectangle(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Rectangle * s = shape->ptrShape;
    Point p1 = s->top;
    Point p2 = s->top;
    p2.y += s->width;
    Point p3 = s->top;
    p3.y += s->width;
    p3.x += s->height;
    Point p4 = s->top;
    p4.x += s->height;
    Shape *l1 = createLineShape(p1.x, p1.y, p2.x, p2.y);
    Shape *l2 = createLineShape(p2.x, p2.y, p3.x, p3.y);
    Shape *l3 = createLineShape(p3.x, p3.y, p4.x, p4.y);
    Shape *l4 = createLineShape(p4.x, p4.y, p1.x, p1.y);
    pixel_ligne(l1, pixel, nb_pixels);
    pixel_ligne(l2, pixel, nb_pixels);
    pixel_ligne(l3, pixel, nb_pixels);
    pixel_ligne(l4, pixel, nb_pixels);
}

void pixel_polygone(Shape* shape, Pixel*** pixel, int* nb_pixels){
    Polygon * s = shape->ptrShape;
    for(int i = 0; i < s->n; i++){
        Point *p1 = s->points[i];
        Point *p2 = NULL;
        if(i + 1 == s->n){
            p2 = s->points[0];
        } else{
            p2 = s->points[i+1];
        }
        Shape *l1 = createLineShape(p1->x, p1->y, p2->x, p2->y);
        pixel_ligne(l1, pixel, nb_pixels);
    }
}

Pixel** create_shape_to_pixel(Shape* shape, int* nb_pixels){
    Pixel ** pixel = (Pixel**) malloc(sizeof(Pixel*));
    switch(shape->shape_type){
        case LINE:
            pixel_ligne(shape, &pixel, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle(shape, &pixel, nb_pixels);
            break;
        case SQUARE:
            pixel_square(shape, &pixel, nb_pixels);
            break;
        case RECTANGLE:
            pixel_rectangle(shape, &pixel, nb_pixels);
            break;
        case POLYGON:
            pixel_polygone(shape, &pixel, nb_pixels);
            break;
        case POINT:
            pixel_point(shape, &pixel, nb_pixels);
            break;
        default:
            break;
    }
    return pixel;
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    for (int i=0; i<nb_pixels; i++){
        free(pixel[i]);
    }
}
