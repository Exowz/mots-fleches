//
// Created by Ewan Kapoor on 28/05/2024.
//

#ifndef MOTS_FLECHES_TOOLS_H
#define MOTS_FLECHES_TOOLS_H

//Bibliothèques

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "../gameplay/gameplay.h"
#include "../keyboard/keyboard.h"
#include "../menu/menu.h"

//Couleur

#define NOIR 0
#define BLEU_FONCE 1
#define VERT_FONCE 2
#define TURQUOISE 3
#define ROUGE_FONCE 4
#define VIOLET 5
#define VERT_CACA_DOIE 6
#define GRIS_CLAIR 7
#define GRIS_FONCE 8
#define BLEU_FLUO 9
#define VERT_FLUO 10
#define TURQUOISE_2 11
#define ROUGE_FLUO 12
#define VIOLET_2 13
#define JAUNE 14
#define BLANC 15

//Fonctions

void setColor(int color);
COORD getCursorPosition();
void setCursorPosition(int x, int y);
void definir_couleur(int couleur);
void positionner_curseur(int x, int y);

#endif //MOTS_FLECHES_TOOLS_H
