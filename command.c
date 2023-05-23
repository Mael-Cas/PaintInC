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

int read_exec_command(Command* command){

    if(command->name == "exit"){
        return 0;
    }else if(command->name == "clear"){
        clear();
    }else if(command->name == "point"){
        return 1;
    }else if(command->name == "line"){
        return 2;
    }else if(command->name == "rectangle"){
        return 3;
    }else if(command->name == "circle"){
        return 4;
    }else if(command->name == "square"){
        return 5;
    }else if(command->name == "polygon"){
        return 6;
    }else if(command->name == "plot"){
        return 7;
    }else if(command->name == "delete"){
        return 8;
    }else if(command->name == "erase"){
        return 9;
    }else if(command->name == "help"){
        return 10;
    }else{
        return 404;
    }
}
void read_from_stdin(Command* command)
{
    char token[50], cle[10];
    char *list_str;
    int i = 0, j, value;
    char *endcle;
    printf(">>");
    fgets(token, 50, stdin);
    while(token[i] != '\n')
    {
        j = 0;

        if (token[i+j] == ' ' || token[i+j] == '\n')
            i++;
        cle[0] = '\0';
        while(token[i+j] != ' ' && token[i+j] != '\n')
        {
            cle[j] = token[i+j];

            if (i == 0 && (token[j+1]==' ' || token[j+1] == '\n'))
            {
                for (int a = 0; a <j+1; a++)
                {
                    command->name[a] = cle[a];
                }

                command->name[j+1] = '\0';
            }


            if (i!=0 && (token[i+j+1]==' ' || token[i+j+1]=='\n'))
            {
                cle[j+1] = '\0';
                endcle = NULL;

                value = strtol(cle, &endcle, 10);
                if (!isdigit(cle[0])) {

                    add_str_param(command, cle);
                }
                else {
                    add_int_param(command, value);
                }
            }
            j++;
        }
        i += j;
    }
}



