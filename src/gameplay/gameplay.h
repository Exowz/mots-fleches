//
// Created by Ewan on 27/06/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

//Bibliothèques

#include "../tools/tools.h"

//Définitions

#define TAILLE_GRILLE_MAX 20

//Fonctions

void jouer_jeu(char **liste_mots, int nb_mots);
void generer_grille(char **grille, char **mots, int nb_mots);
void remplir_espaces_vides(char **grille);
void afficher_grille(char **grille, int curseur_x, int curseur_y, int selectionne[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], int valide[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char **mots_a_trouver, int nb_mots, char **mots_trouves, int nb_trouves);
char** copier_liste_mots(char **liste_mots, int nb_mots);
int mots_restants(char **mots_a_trouver, int nb_mots);
void liberer_liste_mots(char **liste_mots, int nb_mots);
char generer_lettre_aleatoire();
int valider_mot(char **grille, int selectionne[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char **liste_mots, int nb_mots, char **mots_trouves, int *nb_trouves);
int est_mot_dans_liste(char *mot, char **liste_mots, int nb_mots);
int peut_placer_mot(char **grille, int ligne, int col, int direction, char *mot);


#endif //GAMEPLAY_H
