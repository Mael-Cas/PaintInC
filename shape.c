//
// Created by maelc on 24/03/2023.
//

#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

//Point
Point *createPoint(int x, int y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void deletePoint(Point *p) {
    free(p);
}

void printPoint(Point *p) {
    printf("POINT [p(%d, %d)]", p->x, p->y);
}

//Line

Line *createLine(Point *p1, Point *p2) {
    Line *l = malloc(sizeof(Line));
    l->p1 = *p1;
    l->p2 = *p2;
    return l;
}

void deleteLine(Line *l) {
    free(l);
}

void printLine(Line *l) {
    printf("LINE [p1(%d, %d) p2(%d, %d)]", l->p1.x, l->p1.y, l->p2.x, l->p2.y);
}

Square *createSquare(Point *top, int length) {
    Square *s = malloc(sizeof(Square));
    s->top = *top;
    s->length = length;
    return s;
}

void deleteSquare(Square *s) {
    free(s);
}

void printSquare(Square *s) {
    printf("SQUARE [top(%d, %d) length(%d)]", s->top.x, s->top.y, s->length);
}

Rectangle *createRectangle(Point *top, int width, int height) {
    Rectangle *r = malloc(sizeof(Rectangle));
    r->top = *top;
    r->width = width;
    r->height = height;
    return r;
}
void deleteRectangle(Rectangle *r) {
    free(r);
}
void printRectangle(Rectangle *r) {
    printf("RECTANGLE [top(%d, %d) width(%d) height(%d)]", r->top.x, r->top.y, r->width, r->height);
}

Circle *createCircle(Point *center, int radius) {
    Circle *c = malloc(sizeof(Circle));
    c->center = *center;
    c->radius = radius;
    return c;
}

void deleteCircle(Circle *c) {
    free(c);
}

void printCircle(Circle *c) {
    printf("CIRCLE [center(%d, %d) radius(%d)]", c->center.x, c->center.y, c->radius);
}

Polygon *createPolygon(int n) {
    Polygon *p = malloc(sizeof(Polygon));
    p->n = n;
    p->points = malloc(sizeof(Point *) * n);
    return p;
}
void deletePolygon(Polygon *p) {
    free(p);
}
void printPolygon(Polygon *p) {
    printf("POLYGON [n(%d) points(%d, %d)]", p->n, p->points[0]->x, p->points[0]->y);
}