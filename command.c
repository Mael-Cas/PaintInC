//
// Created by maelc on 24/03/2023.
//

#include "command.h"

#include <stdlib.h> // pour la fonction system()
#include <string.h> // pour la fonction strcpy()

void clear() {
#ifdef _WIN32 // pour Windows
    system("cls");
#else // pour les autres systèmes (Unix, Linux, macOS, etc.)
    system("clear");
#endif
}

Command *create_command(char *name) {
    Command *c = malloc(sizeof(Command));
    strcpy(c->name, name);
    c->int_size = 0;
    c->str_size = 0;
    return c;
}
void add_str_param(Command *command, char *param) {
    command->str_params[command->str_size] = param;
    command->str_size++;
}
void add_int_param(Command *command, int param) {
    command->int_params[command->int_size] = param;
    command->int_size++;
}

void free_cmd(Command *command) {
    free(command);
}

int read_exec_command(Command* command){
    
}



