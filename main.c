#include "gameplay/gameplay.h"
#include "keyboard/keyboard.h"
#include "menu/menu.h"
#include "tools/tools.h"

int TAILLE_GRILLE = 15;

int main() {
    menu_principal();
    return 0;
}

void jouer_jeu(char **liste_mots, int nb_mots) {
    Crossword cw;
    cw.taille = TAILLE_GRILLE;
    cw.grille = malloc(cw.taille * sizeof(char*));
    for (int i = 0; i < cw.taille; i++) {
        cw.grille[i] = calloc(cw.taille, sizeof(char));
    }

    cw.mots_a_trouver = liste_mots;
    cw.nb_mots = nb_mots;
    cw.mots_trouves = calloc(nb_mots, sizeof(char*));
    cw.nb_trouves = 0;

    generer_grille(&cw);

    int curseur_x = 0, curseur_y = 0;
    int selectionne[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {0};
    int valide[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {0};

    int continuer_jeu = 1;

    while (continuer_jeu && mots_restants(&cw)) {
        system("cls");
        afficher_grille(&cw, curseur_x, curseur_y);

        handleInput(&cw, &curseur_x, &curseur_y, &continuer_jeu);
    }

    if (continuer_jeu) {
        system("cls");
        printf("GG le boss\n");
    }

    for (int i = 0; i < cw.taille; i++) {
        free(cw.grille[i]);
    }
    free(cw.grille);
    liberer_mots(&cw);
}