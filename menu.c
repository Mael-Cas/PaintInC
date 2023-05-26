//
// Created by alexa on 21/04/2023.
//

#include "menu.h"
#include "shape.h"
#include "area.h"



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


void menuPrincipal(liste lst_shape, Area * area){
    char choix;
    printf("Veuillez choisir une action : ");
    printf("\n\tA- Ajouter une forme");
    printf("\n\tB- Afficher la liste des formes");
    printf("\n\tC- Supprimer une forme");
    printf("\n\tD- Imprimer la zone de dessin");
    /* Fonctions pas encore réalisées
    printf("\tE- Aide");*/
    printf("\nVotre choix : ");
    scanf(" %c", &choix);
    switch (choix) {
        case 'A':
            choixCreation(lst_shape, area);
        case 'B':
            affichageForme(lst_shape, area);
        case 'C':
            lst_shape = suppForme(lst_shape, area);
            menuPrincipal(lst_shape, area);
        case 'D':
            draw_area(area);
            print_area(area);
        default:
            printf("\nProbleme lors du choix\n");
            menuPrincipal(lst_shape, area);
    }
}

void choixCreation(liste lst_shape, Area * area){
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
            menuPoint(lst_shape, area);
        case 2:
            menuLigne(lst_shape, area);
        case 3:
            menuCercle(lst_shape, area);
        case 4:
            menuCarre(lst_shape, area);
        case 5:
            menuRectangle(lst_shape, area);
        case 6:
            menuPolygone(lst_shape, area);
        case 7:
            menuPrincipal(lst_shape, area);
        default:
            printf("Probleme lors du choix\n");
            choixCreation(lst_shape, area);
    }

}

void menuPoint(liste lst_shape, Area * area){
    int x, y;
    printf("Saisir les informations du point x y : ");
    scanf("%d %d", &x, &y);
    Shape *p = createPointShape(x, y);
    lst_shape = ajoutShape(p, lst_shape);
    add_shape_to_area(area, p);
    printf("\n");
    menuPrincipal(lst_shape, area);
}

void menuLigne(liste lst_shape, Area * area){
    int x1, y1, x2, y2;
    printf("Saisir les informations de la ligne : ");
    printf("\n\tSaisir les informations du premier point x1 y1 : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir les informations du point x2 y2 : ");
    scanf("%d %d", &x2, &y2);
    Shape * l = createLineShape(x1, y1, x2, y2);
    lst_shape = ajoutShape(l, lst_shape);
    add_shape_to_area(area, l);
    printf("\n");
    menuPrincipal(lst_shape, area);
}


void menuCercle(liste lst_shape, Area * area){
    int x1, y1, radius;
    printf("Saisir les informations du cerlce : ");
    printf("\n\tSaisir les coordonnees du centre x y : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir la taille du rayon : ");
    scanf("%d", &radius);
    Shape * c = createCircleShape(x1, y1, radius);
    lst_shape = ajoutShape(c, lst_shape);
    add_shape_to_area(area, c);
    printf("\n");
    menuPrincipal(lst_shape, area);


}

void menuCarre(liste lst_shape, Area * area){
    int x1, y1, length;
    printf("Saisir les informations du carre : ");
    printf("\n\tSaisir les informations du point x y : ");
    scanf("%d %d", &x1, &y1);
    printf("\tSaisir la longueur du cote : ");
    scanf("%d", &length);
    Shape  * s = createSquareShape(x1, y1, length);
    lst_shape = ajoutShape(s, lst_shape);
    add_shape_to_area(area, s);
    printf("\n");
    menuPrincipal(lst_shape, area);
}

void menuRectangle(liste lst_shape, Area * area){
    int x,y,w,h;
    printf("Saisir les informations du rectangle : ");
    printf("\n\tSaisir les informations du point x y : ");
    scanf("%d %d", &x, &y);
    printf("\tSaisir la hauteur et la largeur du rectangle h w : ");
    scanf("%d %d", &h, &w);
    Shape * r = createRectangleShape(x,y,w,h);
    lst_shape = ajoutShape(r, lst_shape);
    add_shape_to_area(area, r);
    printf("\n");
    menuPrincipal(lst_shape, area);
}

void menuPolygone(liste lst_shape, Area * area){
    int n;
    printf("Saisir les informations du polygone : ");
    printf("\n\tVeuillez saisir un nombre de points : ");
    scanf("%d", &n);
    int *lst = (int*) malloc(n*2* sizeof(int));
    int cpt=1;
    for (int i = 0; i < n*2; i+=2) {
        printf("\tVeuillez saisir les informations du point %d x y : ", cpt);
        scanf("%d %d", (lst+i), (lst+i+1));
        cpt++;
    }
    Shape * p = createPolygonShape(lst, n*2);
    lst_shape = ajoutShape(p, lst_shape);
    add_shape_to_area(area, p);
    printf("\n");
    menuPrincipal(lst_shape, area);
}

void affichageForme(liste lst_shape, Area * area){
    liste temp = lst_shape;
    printf("\nListe des formes : ");
    while (temp != NULL){
        printf("\n\t%d : ", temp->shape->id);
        printShape(temp->shape);
        temp = temp->succ;
    }
    printf("\n");
    menuPrincipal(lst_shape, area);
}

liste suppForme(liste lst_shape, Area * area){
    liste temp = lst_shape;
    printf("\nListe des formes : ");
    while (temp != NULL){
        printf("\n\t%d : ", temp->shape->id);
        printShape(temp->shape);
        temp = temp->succ;
    }
    printf("\n");
    int id=0;
    int cond = 1;
    printf("Veuillez rentrer l'id de la forme à supprimer : ");
    scanf("%d", &id);
    if (lst_shape != NULL){
        maillon * tmp = lst_shape;
        maillon * ptmp = NULL;
        while (tmp != NULL && cond == 1){
            if (tmp->shape->id == id){

                if (ptmp == NULL){
                    lst_shape = tmp->succ;
                    remove_shape_to_area(area, tmp->shape);
                    free(tmp);
                    free(ptmp);
                    cond = 0;
                } else if (tmp->succ == NULL){
                    remove_shape_to_area(area, tmp->shape);
                    ptmp->succ = NULL;
                    free(tmp);
                    cond = 0;
                } else{
                    ptmp->succ = tmp->succ;
                    remove_shape_to_area(area,tmp->shape);
                    free(tmp);
                    cond = 0;
                }
            } else{
                ptmp = tmp;
                tmp = tmp->succ;
            }
        }
    }
    printf("\n");
    return lst_shape;
}

void aide(){
    printf("Listes des commandes : \n");
    printf("\texit\t|\tQuitte le programme\n");
    printf("\tclear\t|\tClear le terminal\n");
    printf("\tpoint x y\t|\tCreer un point de coordonnees x,y\n");
    printf("\tline x1 y1 x2 y2\t|\tCreer une ligne\n");
    printf("\trectangle x y width height\t|\tCreer un rectangle\n");
    printf("\tsquare x y length\t|\tCreer un carré\n");
    printf("\tcircle x y radius\t|\tCreer un cercle\n");
    printf("\tpolygon x1 y1 x2 y2 ... xn yn\t|\tCreer un polygon de n points\n");
    printf("\tplot\t|\tAfficher graphiquement la zone de dessin\n");
    printf("\tshapes\t|\tAfficher la liste des formes\n");
    printf("\tdelete id\t|\tSupprimer la forme d'identifiant id\n");
}

liste suppFormeBash(liste lst_shape, Area * area, int id){
    int cond = 1;
    if (lst_shape != NULL){
        maillon * tmp = lst_shape;
        maillon * ptmp = NULL;
        while (tmp != NULL && cond == 1){
            if (tmp->shape->id == id){

                if (ptmp == NULL){
                    lst_shape = tmp->succ;
                    remove_shape_to_area(area, tmp->shape);
                    free(tmp);
                    free(ptmp);
                    cond = 0;
                } else if (tmp->succ == NULL){
                    remove_shape_to_area(area, tmp->shape);
                    ptmp->succ = NULL;
                    free(tmp);
                    cond = 0;
                } else{
                    ptmp->succ = tmp->succ;
                    remove_shape_to_area(area,tmp->shape);
                    free(tmp);
                    cond = 0;
                }
            } else{
                ptmp = tmp;
                tmp = tmp->succ;
            }
        }
    }
    return lst_shape;
}