//
// Created by alexa on 19/04/2023.
//

#include "id.h"

unsigned int getNextId(){
    return ++globalId;
}