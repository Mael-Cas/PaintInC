//
// Created by maelc on 24/03/2023.
//

#ifndef PAINTINC_COMMAND_H
#define PAINTINC_COMMAND_H

struct command{
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
};
typedef struct command Command;

Command* create_command(char* name);
void add_str_param(Command* command, char* param);
void add_int_param(Command* command, int param);
void free_cmd(Command* command);
int read_exec_cmd(Command* command);
void read_from_stdin(Command* command);



void clear();


#endif //PAINTINC_COMMAND_H