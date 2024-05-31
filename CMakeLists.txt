cmake_minimum_required(VERSION 3.26)
project(mots_fleches C)

set(CMAKE_C_STANDARD 11)

add_executable(mots_fleches
        main.c
        src/menu/menu.h
        src/tools/tools.h
        src/keyboard/keyboard.h
        src/tools/tools.c
        src/menu/menu.c
        src/keyboard/keyboard.c
        src/gameplay/gameplay.h
        src/gameplay/gameplay.c)
