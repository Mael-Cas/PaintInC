//
// Created by alexa on 21/04/2023.
//

#ifndef PAINTINC_MENU_H
#define PAINTINC_MENU_H
#include "shape.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct maillon{
    Shape* shape;
    struct maillon *succ;
}maillon;

typedef maillon* liste;

void ajoutShape(Shape* shape, liste lst_shape);
void menuPrincipal(liste lst_shape);
void choixCreation(liste lst_shape);
void affichageForme(liste lst_shape);
void menuPoint(liste lst_shape);
void menuLigne(liste lst_shape);
void menuCercle(liste lst_shape);
void menuCarre(liste lst_shape);
void menuRectangle(liste lst_shape);
void menuPolygone(liste lst_shape);
void suppForme(liste lst_shape);
void dessin(liste lst_shape);
void aide();


#endif //PAINTINC_MENU_H
