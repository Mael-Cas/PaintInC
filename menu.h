//
// Created by alexa on 21/04/2023.
//

#ifndef PAINTINC_MENU_H
#define PAINTINC_MENU_H
#include "shape.h"
#include <stdlib.h>
#include <stdio.h>
#include "area.h"

typedef struct maillon{
    Shape* shape;
    struct maillon *succ;
}maillon;

typedef maillon* liste;

liste ajoutShape(Shape* shape, liste lst_shape);
void menuPrincipal(liste lst_shape, Area * area);
void choixCreation(liste lst_shape, Area * area);
void affichageForme(liste lst_shape, Area * area);
void menuPoint(liste lst_shape, Area * area);
void menuLigne(liste lst_shape, Area * area);
void menuCercle(liste lst_shape, Area * area);
void menuCarre(liste lst_shape, Area * area);
void menuRectangle(liste lst_shape, Area * area);
void menuPolygone(liste lst_shape, Area * area);
liste suppForme(liste lst_shape, Area * area);
void dessin(liste lst_shape);
void aide();


#endif //PAINTINC_MENU_H
