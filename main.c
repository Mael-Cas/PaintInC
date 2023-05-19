#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "command.h"
#include "menu.h"
#include "area.h"

int main() {
    liste lst_shape=NULL;
    Area * area = create_area(30, 30);
    menuPrincipal(lst_shape, area);

    return 0;
}

