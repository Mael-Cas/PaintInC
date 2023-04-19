cmake_minimum_required(VERSION 3.24)
project(PaintInC C)

set(CMAKE_C_STANDARD 11)

add_executable(PaintInC main.c drawing.c drawing.h shape.c shape.h command.c command.h id.c id.h)
