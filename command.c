//
// Created by maelc on 24/03/2023.
//

#include "command.h"

#include <stdlib.h> // pour la fonction system()
#include <stdio.h> // pour la fonction printf()
#include <string.h> // pour la fonction strcpy()
#include <ctype.h> // pour la fonction

void clear() {
    printf("\033[2J");
    printf("\033[0;0H");
}

Command *create_command() {
    Command *c = malloc(sizeof(Command));

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

int read_exec_cmd(Command* command){

    if(strcmp(command->name, "exit") == 0){
        return 0;
    }else if(strcmp(command->name, "clear") == 0){
        clear();
    }else if(strcmp(command->name, "point")== 0){
        return 1;
    }else if(strcmp(command->name, "line")== 0){
        return 2;
    }else if(strcmp(command->name, "rectangle")== 0){
        return 3;
    }else if(strcmp(command->name, "circle")== 0){
        return 4;
    }else if(strcmp(command->name, "square")==0){
        return 5;
    }else if(strcmp(command->name, "polygon")==0){
        return 6;
    }else if(strcmp(command->name, "plot")==0){
        return 7;
    }else if(strcmp(command->name, "delete")== 0){
        return 8;
    }else if(strcmp(command->name, "erase")== 0){
        return 9;
    }else if(strcmp(command->name, "help")== 0){
        return 10;
    }else if(strcmp(command->name, "shapes")== 0) {
        return 11;
    }else{
        return 404;
    }
}
void read_from_stdin(Command* command)
{
    char input[50];
    printf(">>");
    fgets(input, sizeof(input), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    char* token = strtok(input, " "); // Séparer la phrase par des espaces
    int index = 0;

    while (token != NULL) {
        if (index == 0) {
            strcpy(command->name, token);
        } else {
            command->int_params[index - 1] = atoi(token);

        }

        token = strtok(NULL, " ");
        index++;
    }

    command->int_size = index - 1;
}