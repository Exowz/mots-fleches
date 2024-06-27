//
// Created by Ewan Kapoor on 31/05/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define TAILLE_GRILLE_MAX 20

#include "../tools/tools.h"

typedef struct {
    char **grille;
    int taille;
    char **mots_a_trouver;
    int nb_mots;
    char **mots_trouves;
    int nb_trouves;
    int selectionne[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX];
    int valide[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX];
} Crossword;

void generer_grille(Crossword *cw);
void remplir_espaces_vides(Crossword *cw);
void afficher_grille(Crossword *cw, int curseur_x, int curseur_y);
int valider_mot(Crossword *cw, int *curseur_x, int *curseur_y);
int peut_placer_mot(Crossword *cw, int ligne, int col, int direction, char *mot);
int mots_restants(Crossword *cw);
void liberer_mots(Crossword *cw);
char generer_lettre_aleatoire();


#endif //MOTS_FLECHES_GAMEPLAY_H
