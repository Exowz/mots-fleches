cmake_minimum_required(VERSION 3.28)
project(mots_fleches_malloc_modulaire C)

set(CMAKE_C_STANDARD 23)

add_executable(mots_fleches_malloc_modulaire main.c
        src/gameplay/gameplay.c
        src/gameplay/gameplay.h
        src/menu/menu.c
        src/menu/menu.h
        src/tools/tools.c
        src/tools/tools.h
        src/tools/tools.h
        src/tools/tools.h)
