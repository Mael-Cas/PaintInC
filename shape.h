//
// Created by maelc on 24/03/2023.
//

#ifndef PAINTINC_SHAPE_H
#define PAINTINC_SHAPE_H

typedef struct Point {
    int x, y; // Coordonnées
} Point;

typedef struct Line {
    Point p1, p2; // Deux points
} Line;

typedef struct Circle {
    Point center; // Coordonnés du centre
    int radius;
} Circle;

typedef struct Square {
    Point top; // Coordonnés coin supérieur gauche
    int length;
} Square;

typedef struct Rectangle {
    Point top;// Coin supérieur gauche
    int width, height;// Longueur et largeur
} Rectangle;

typedef struct Polygon {
    int n;
    Point ** points;
} Polygon;

Point *createPoint(int x, int y);
void deletePoint(Point *p);
void printPoint(Point *p);

Square *createSquare(Point *top, int length);
void deleteSquare(Square *s);
void printSquare(Square *s);

Rectangle *createRectangle(Point *top, int width, int height);
void deleteRectangle(Rectangle *r);
void printRectangle(Rectangle *r);

Circle *createCircle(Point *center, int radius);
void deleteCircle(Circle *c);
void printCircle(Circle *c);

Polygon *createPolygon(int n);
void deletePolygon(Polygon *p);
void printPolygon(Polygon *p);

#endif //PAINTINC_SHAPE_H
