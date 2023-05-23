#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "command.h"
#include "menu.h"
#include "area.h"

int main() {
    liste lst_shape=NULL;
    Area * area = create_area(30, 30);
    Shape *s = NULL;
    //menuPrincipal(lst_shape, area);
    Command* command = create_command();
    read_from_stdin(command);
    int id = read_exec_cmd(command);

    switch (id) {
        case 1 :
            s = createPointShape(command->int_params[0], command->int_params[1]);
            lst_shape = ajoutShape(s, lst_shape);
            add_shape_to_area(area, s);
            draw_area(area);
            print_area(area);
            break;
        case 2 :
            s = createLineShape(command->int_params[0], command->int_params[1], command->int_params[2], command->int_params[3]);
            lst_shape = ajoutShape(s, lst_shape);
            add_shape_to_area(area, s);
            draw_area(area);
            print_area(area);
            break;
        case 3 :
            s = createRectangleShape(command->int_params[0], command->int_params[1], command->int_params[2], command->int_params[3]);
            lst_shape = ajoutShape(s, lst_shape);
            add_shape_to_area(area, s);
            draw_area(area);
            print_area(area);
            break;
        case 4 :
            s = createCircleShape(command->int_params[0], command->int_params[1], command->int_params[2]);
            lst_shape = ajoutShape(s, lst_shape);
            add_shape_to_area(area, s);
            draw_area(area);
            print_area(area);
            break;
        case 5 :
            s = createSquareShape(command->int_params[0], command->int_params[1], command->int_params[2]);
            lst_shape = ajoutShape(s, lst_shape);
            add_shape_to_area(area, s);
            draw_area(area);
            print_area(area);
            break;
        case 6 :
            break;
        case 7 :
            draw_area(area);
            print_area(area);
            break;
        case 8 :
            break;
        case 9 :
            erase_area(area);
            draw_area(area);
            print_area(area);
            break;
        case 10 :
            aide();
            break;

        default:
            printf("Commande inconnue\n");
            break;
    }
    return 0;
}

