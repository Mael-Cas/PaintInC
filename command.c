//
// Created by maelc on 24/03/2023.
//

#include "command.h"

#include <stdlib.h> // pour la fonction system()

void clear() {
#ifdef _WIN32 // pour Windows
    system("cls");
#else // pour les autres systèmes (Unix, Linux, macOS, etc.)
    system("clear");
#endif
}




