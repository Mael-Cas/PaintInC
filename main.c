#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "command.h"
#include "menu.h"
#include "area.h"

int main() {
    liste lst_shape = NULL;
    Area *area = create_area(30, 30);
    Shape *s = NULL;

    printf("Voulez-vous utiliser l'interface graphique ? (y/n)\n");
    char c = getchar();
    getchar();
    if (c == 'y') {
        menuPrincipal(lst_shape, area);
    } else {
        printf("Veuillez entrer une commande : \n");
    }
    //menuPrincipal(lst_shape, area);

    while (1) {



            Command *command = create_command();
            read_from_stdin(command);
            int id = read_exec_cmd(command);
            int *lst = (int *) malloc(command->int_size * 2 * sizeof(int));
            int cpt = 1;
            liste temp = NULL;


            switch (id) {
                case 0 :
                    clear();
                    printf("Au revoir !\n");
                    exit(0);
                    break;
                case 1 :
                    clear();
                    s = createPointShape(command->int_params[0], command->int_params[1]);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 2 :
                    clear();
                    s = createLineShape(command->int_params[0], command->int_params[1], command->int_params[2],
                                        command->int_params[3]);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 3 :
                    clear();
                    s = createRectangleShape(command->int_params[0], command->int_params[1], command->int_params[2],
                                             command->int_params[3]);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 4 :
                    clear();
                    s = createCircleShape(command->int_params[0], command->int_params[1], command->int_params[2]);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 5 :
                    clear();
                    s = createSquareShape(command->int_params[0], command->int_params[1], command->int_params[2]);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 6 :
                    clear();
                    for (int i = 0; i < command->int_size * 2; i += 2) {
                        lst[i] = command->int_params[i];
                        lst[i + 1] = command->int_params[i + 1];
                    }
                    s = createPolygonShape(lst, command->int_size);
                    lst_shape = ajoutShape(s, lst_shape);
                    add_shape_to_area(area, s);
                    draw_area(area);
                    print_area(area);
                    break;
                case 7 :
                    clear();
                    draw_area(area);
                    print_area(area);
                    break;
                case 8 :
                    clear();
                    lst_shape = suppFormeBash(lst_shape, area, command->int_params[0]);
                    break;
                case 9 :
                    clear();
                    erase_area(area);
                    draw_area(area);
                    print_area(area);
                    break;
                case 10 :
                    clear();
                    aide();
                    break;
                case 11 :
                    clear();
                    temp = lst_shape;
                    printf("\nListe des formes : ");
                    while (temp != NULL){
                        printf("\n\t%d : ", temp->shape->id);
                        printShape(temp->shape);
                        temp = temp->succ;
                    }
                    printf("\n");
                    break;
                default:
                    clear();
                    printf("Commande inconnue\n");
                    break;
            }
            free_cmd(command);

        }
        return 0;
    }

