//
// Created by Ewan Kapoor on 31/05/2024.
//

#include "gameplay.h"

void generer_grille(Crossword *cw) {
    srand(time(NULL));
    for (int i = 0; i < cw->nb_mots; i++) {
        int place = 0;
        while (!place) {
            int direction = rand() % 4;
            int longueur_mot = strlen(cw->mots_a_trouver[i]);
            int ligne, col;

            switch (direction) {
                case 0: // horizontal gauche a droite
                    ligne = rand() % cw->taille;
                    col = rand() % (cw->taille - longueur_mot);
                    if (peut_placer_mot(cw, ligne, col, direction, cw->mots_a_trouver[i])) {
                        for (int j = 0; j < longueur_mot; j++) {
                            cw->grille[ligne][col + j] = cw->mots_a_trouver[i][j];
                        }
                        place = 1;
                    }
                    break;
                case 1: // horizontal droite a gauche
                    ligne = rand() % cw->taille;
                    col = rand() % (cw->taille - longueur_mot) + longueur_mot - 1;
                    if (peut_placer_mot(cw, ligne, col, direction, cw->mots_a_trouver[i])) {
                        for (int j = 0; j < longueur_mot; j++) {
                            cw->grille[ligne][col - j] = cw->mots_a_trouver[i][j];
                        }
                        place = 1;
                    }
                    break;
                case 2: // vertical haut en bas
                    ligne = rand() % (cw->taille - longueur_mot);
                    col = rand() % cw->taille;
                    if (peut_placer_mot(cw, ligne, col, direction, cw->mots_a_trouver[i])) {
                        for (int j = 0; j < longueur_mot; j++) {
                            cw->grille[ligne + j][col] = cw->mots_a_trouver[i][j];
                        }
                        place = 1;
                    }
                    break;
                case 3: // vertical bas en haut
                    ligne = rand() % (cw->taille - longueur_mot) + longueur_mot - 1;
                    col = rand() % cw->taille;
                    if (peut_placer_mot(cw, ligne, col, direction, cw->mots_a_trouver[i])) {
                        for (int j = 0; j < longueur_mot; j++) {
                            cw->grille[ligne - j][col] = cw->mots_a_trouver[i][j];
                        }
                        place = 1;
                    }
                    break;
            }
        }
    }
    remplir_espaces_vides(cw);
}

int peut_placer_mot(Crossword *cw, int ligne, int col, int direction, char *mot) {
    int longueur_mot = strlen(mot);
    switch (direction) {
        case 0: // horizontal gauche a droite
            for (int j = 0; j < longueur_mot; j++) {
                if (cw->grille[ligne][col + j] != '\0' && cw->grille[ligne][col + j] != mot[j]) {
                    return 0;
                }
            }
            break;
        case 1: // horizontal droite a gauche
            for (int j = 0; j < longueur_mot; j++) {
                if (cw->grille[ligne][col - j] != '\0' && cw->grille[ligne][col - j] != mot[j]) {
                    return 0;
                }
            }
            break;
        case 2: // vertical haut en bas
            for (int j = 0; j < longueur_mot; j++) {
                if (cw->grille[ligne + j][col] != '\0' && cw->grille[ligne + j][col] != mot[j]) {
                    return 0;
                }
            }
            break;
        case 3: // vertical bas en haut
            for (int j = 0; j < longueur_mot; j++) {
                if (cw->grille[ligne - j][col] != '\0' && cw->grille[ligne - j][col] != mot[j]) {
                    return 0;
                }
            }
            break;
    }
    return 1;
}

void remplir_espaces_vides(Crossword *cw) {
    for (int i = 0; i < cw->taille; i++) {
        for (int j = 0; j < cw->taille; j++) {
            if (cw->grille[i][j] == '\0') {
                cw->grille[i][j] = generer_lettre_aleatoire();
            }
        }
    }
}

char generer_lettre_aleatoire() {
    return 'A' + rand() % 26;
}

void afficher_grille(Crossword *cw, int curseur_x, int curseur_y) {
    for (int i = 0; i < cw->taille; i++) {
        for (int j = 0; j < cw->taille; j++) {
            positionner_curseur(j * 3, i);
            if (i == curseur_y && j == curseur_x) {
                definir_couleur(1); // Curseur cyan
            } else if (cw->valide[i][j]) {
                definir_couleur(3); // Valide
            } else if (cw->selectionne[i][j]) {
                definir_couleur(2); // Selection
            } else {
                definir_couleur(0); // Damier vert et gris
            }
            printf(" %c ", cw->grille[i][j]); // Ajout d'espaces pour centrer les lettres
            printf("\033[0m"); // Reinitialiser les couleurs apres chaque cellule
        }
        printf("\n"); // Retour a la ligne apres chaque ligne de la grille
    }

    // Affichage des mots a rechercher
    int list_x = cw->taille * 3 + 5; // Position x a droite de la grille
    int list_y = 0; // Position y en haut de la grille
    positionner_curseur(list_x, list_y++);
    printf("| %-40s |\n", "Mots a rechercher dans la grille");
    for (int i = 0; i < cw->nb_mots; i++) {
        if (cw->mots_a_trouver[i] != NULL) {
            positionner_curseur(list_x, list_y++);
            printf("| %-40s |\n", cw->mots_a_trouver[i]);
        }
    }

    // Affichage des mots trouves
    list_y++;
    positionner_curseur(list_x, list_y++);
    printf("| %-40s |\n", "Mots trouves");
    for (int i = 0; i < cw->nb_trouves; i++) {
        positionner_curseur(list_x, list_y++);
        printf("| %-40s |\n", cw->mots_trouves[i]);
    }
}

int valider_mot(Crossword *cw) {
    char mot_selectionne[TAILLE_GRILLE_MAX] = "";
