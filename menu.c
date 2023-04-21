//
// Created by alexa on 21/04/2023.
//

#include "menu.h"
#include "shape.h"

liste ajoutShape(Shape* shape, liste lst_shape){
    maillon *nv = (maillon*) malloc(sizeof(maillon));
    nv->shape = shape;
    nv->succ = NULL;
    if (lst_shape == NULL){
        lst_shape = nv;
    } else{
        maillon * tmp = lst_shape;
        while (tmp->succ != NULL){
            tmp = tmp->succ;
        }
        tmp->succ = nv;
    }
    return lst_shape;
}


void menuPrincipal(liste lst_shape){
    char choix;
    printf("Veuillez choisir une action : ");
    printf("\n\tA- Ajouter une forme");
    printf("\n\tB- Afficher la liste des formes");
    /* Fonctions pas encore réalisées
    printf("\tC- Supprimer une forme");
    printf("\tD- Tracer le dessin");
    printf("\tE- Aide");*/
    printf("\nVotre choix : ");
    scanf(" %c", &choix);
    switch (choix) {
        case 'A':
            choixCreation(lst_shape);
        case 'B':
            affichageForme(lst_shape);
        default:
            printf("\nProbleme lors du choix\n");
            menuPrincipal(lst_shape);
    }
}

void choixCreation(liste lst_shape){
    int choice=0;
    printf("Veuillez choisir un action : ");
    printf("\n\t1- Ajouter un point");
    printf("\n\t2- Ajouter une ligne");
    printf("\n\t3- Ajouter un cercle");
    printf("\n\t4- Ajouter un carre");
    printf("\n\t5- Ajouter un rectangle");
    printf("\n\t6- Ajouter un polygone");
    printf("\n\t7- Revenir au menu precedent");
    printf("\nVotre choix : ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            menuPoint(lst_shape);
        case 2:
            menuLigne(lst_shape);
        case 3:
            menuCercle(lst_shape);
        case 4:
            menuCarre(lst_shape);
        case 5:
            menuRectangle(lst_shape);
        case 6:
            menuPolygone(lst_shape);
        case 7:
            menuPrincipal(lst_shape);
        default:
            printf("Probleme lors du choix\n");
            choixCreation(lst_shape);
    }

}

void menuPoint(liste lst_shape){
    int x, y;
    printf("Saisir les informations du point x y : ");
    scanf("%d %d", &x, &y);
    lst_shape = ajoutShape(createPointShape(x, y), lst_shape);
    printf("\n");
    menuPrincipal(lst_shape);
}

void menuLigne(liste lst_shape){
    int x1, y1, x2, y2;
    printf("Saisir les informations de la ligne : ");
    printf("\n\tSaisir les informations du premier point x1 y1 : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir les informations du point x y : ");
    scanf("%d %d", &x2, &y2);
    lst_shape = ajoutShape(createLineShape(x1, y1, x2, y2), lst_shape);
    printf("\n");
    menuPrincipal(lst_shape);
}


void menuCercle(liste lst_shape){
    int x1, y1, radius;
    printf("Saisir les informations du cerlce : ");
    printf("\n\tSaisir les coordonnées du centre : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir la taille du rayon : ");
    scanf("%d", &radius);
    lst_shape = ajoutShape(createCircleShape(x1, y1, radius), lst_shape);
    printf("\n");
    menuPrincipal(lst_shape);


}

void menuCarre(liste lst_shape){
    int x1, y1, length;
    printf("Saisir les informations du carre : ");
    printf("\n\tSaisir les informations du point x y : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir la longueur du cote : ");
    scanf("%d", &length);
    lst_shape = ajoutShape(createSquareShape(x1, y1, length), lst_shape);
    printf("\n");
    menuPrincipal(lst_shape);
}

void menuRectangle(liste lst_shape){
    int x,y,w,h;
    printf("Saisir les informations du rectangle : ");
    printf("\n\tSaisir les informations du point x y : ");
    scanf("%d %d", &x, &y);
    printf("\tSaisir la hauteur et la largeur du rectangle h w : ");
    scanf("%d %d", &h, &w);
    lst_shape = ajoutShape(createRectangleShape(x,y,w,h), lst_shape);
    printf("\n");
    menuPrincipal(lst_shape);
}

void menuPolygone(liste lst_shape){
    printf("En construction");
}

void affichageForme(liste lst_shape){
    liste temp = lst_shape;
    printf("\nListe des formes : ");
    do{
        if (temp->shape->shape_type == POINT){
            Point *p = temp->shape->ptrShape;
            printf("\n\t%d : Point %d %d", temp->shape->id, p->x, p->y);
        }
        if (temp->shape->shape_type == LINE){
            Line *l = temp->shape->ptrShape;
            printf("\n\t%d : Ligne %d %d | %d %d", temp->shape->id, l->p1.x, l->p1.y, l->p2.x, l->p2.y);
        }
        if (temp->shape->shape_type == CIRCLE){
            Circle *c = temp->shape->ptrShape;
            printf("\n\t%d : Cercle %d %d | %d", temp->shape->id, c->center.x, c->center.y, c->radius);
        }
        if (temp->shape->shape_type == SQUARE){
            Square *s = temp->shape->ptrShape;
            printf("\n\t%d : Carre %d %d | %d", temp->shape->id, s->top.x, s->top.y, s->length);
        }
        if (temp->shape->shape_type == RECTANGLE){
            Rectangle *s = temp->shape->ptrShape;
            printf("\n\t%d : Rectangle %d %d | %d | %d ", temp->shape->id, s->top.x, s->top.y, s->width, s->height);
        }
        if (temp->shape->shape_type == POLYGON){
            Point *p = temp->shape->ptrShape;
            printf("\n\t%d : Point %d %d", temp->shape->id, p->x, p->y);
        }
        temp = temp->succ;
    } while (temp != NULL);
    printf("\n");
    menuPrincipal(lst_shape);
}