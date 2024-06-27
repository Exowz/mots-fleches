//
// Created by Ewan Kapoor on 28/05/2024.
//

#include "keyboard.h"

void handleInput(Crossword *cw, int *curseur_x, int *curseur_y, int *selecting, char *inputWord) {
    int ch = _getch();
    if (ch == 224) { // Arrow keys
        ch = _getch();
        if (ch == 72 && *curseur_y > 0) (*curseur_y)--; // Up
        if (ch == 80 && *curseur_y < cw->taille - 1) (*curseur_y)++; // Down
        if (ch == 75 && *curseur_x > 0) (*curseur_x)--; // Left
        if (ch == 77 && *curseur_x < cw->taille - 1) (*curseur_x)++; // Right
    } else if (ch == 13) { // Enter key
        if (!*selecting) {
            *selecting = 1;
            inputWord[0] = '\0';
        }
        strncat(inputWord, &cw->grille[*curseur_y][*curseur_x], 1);
    } else if (ch == 8) { // Backspace key
        if (*selecting && strlen(inputWord) > 0) {
            inputWord[strlen(inputWord) - 1] = '\0';
            if (strlen(inputWord) == 0) {
                *selecting = 0;
            }
        }
    } else if (ch == 'q') { // Quit
        exit(0);
    } else if (ch == ' ' && strlen(inputWord) > 0) {
        if (valider_mot(cw)) {
            for (int i = 0; i < cw->taille; i++) {
                for (int j = 0; j < cw->taille; j++) {
                    if (cw->selectionne[i][j]) {
                        cw->valide[i][j] = 1;
                        cw->selectionne[i][j] = 0;
                    }
                }
            }
        } else {
            for (int i = 0; i < cw->taille; i++) {
                for (int j = 0; j < cw->taille; j++) {
                    cw->selectionne[i][j] = 0;
                }
            }
        }
    }
}
