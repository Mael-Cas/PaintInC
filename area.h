//
// Created by alexa on 12/05/2023.
//

#ifndef PAINTINC_AREA_H
#define PAINTINC_AREA_H
#include "shape.h"

#define SHAPE_MAX 100
#define BOOL int

struct area{
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX];
    int nb_shape;
};
typedef struct area Area;

struct pixel{
    int px;
    int py;
};
typedef struct pixel Pixel;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void remove_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);

void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);
void pixel_point(Shape* shape, Pixel*** pixel, int* nb_pixels);
void pixel_ligne(Shape* shape, Pixel*** pixel, int* nb_pixels);
void pixel_square(Shape* shape, Pixel*** pixel, int* nb_pixels);
void pixel_rectangle(Shape* shape, Pixel*** pixel, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel, int* nb_pixels);
void pixel_polygon(Shape* shape, Pixel*** pixel, int* nb_pixels);

Pixel** create_shape_to_pixel(Shape* shape, int *nb_pixels);

#endif //PAINTINC_AREA_H
