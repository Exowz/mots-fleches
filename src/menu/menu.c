//
// Created by Ewan Kapoor on 28/05/2024.
//

#include "menu.h"

void choisir_theme(char *theme) {
    int choix;
    printf("Choisissez un theme:\n");
    printf("1. Programmation\n");
    printf("2. Jeux videos\n");
    printf("3. Animaux\n");
    printf("4. Pays\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            strcpy(theme, "Programmation");
            break;
        case 2:
            strcpy(theme, "Jeux videos");
            break;
        case 3:
            strcpy(theme, "Animaux");
            break;
        case 4:
            strcpy(theme, "Pays");
            break;
        default:
            printf("Choix invalide. Par defaut: Programmation.\n");
            strcpy(theme, "Programmation");
            break;
    }
}

void menu_principal() {
    int choix;
    char theme[20];
    char *mots_programmation[] = {"variable", "fonction", "compilation", "boucle", "tableau", "pointeur", "objet", "classe", "heritage", "polymorphisme", "recursivite", "algorithme", "debugger"};
    char *mots_jeux_videos[] = {"mario", "zelda", "minecraft", "fortnite", "overwatch", "valorant", "cyberpunk", "halo", "destiny", "pokemon", "fallout", "skyrim"};
    char *mots_animaux[] = {"alligator", "baleine", "castor", "elan", "grenouille", "lamantin", "okapi", "panthere", "pie", "ragondin", "taupe", "tortue", "yack"};
    char *mots_pays[] = {"albanie", "bahamas", "chili", "danemark", "finlande", "georgie", "haïti", "inde", "japon", "kenya", "lituanie", "mexique", "norvege", "perou", "roumanie", "senegal", "thaïlande"};

    int sortie_jeu = 0;

    while (!sortie_jeu) {
        system("cls");
        printf("Menu Principal:\n");
        printf("1. Choisir un theme\n");
        printf("2. Choisir la taille de la grille\n");
        printf("3. Ajouter une nouvelle liste de mots\n");
        printf("4. Quitter le jeu\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                choisir_theme(theme);
                Crossword cw;
                cw.taille = TAILLE_GRILLE;
                if (strcmp(theme, "Programmation") == 0) {
                    jouer_jeu(mots_programmation, sizeof(mots_programmation) / sizeof(mots_programmation[0]));
                } else if (strcmp(theme, "Jeux videos") == 0) {
                    jouer_jeu(mots_jeux_videos, sizeof(mots_jeux_videos) / sizeof(mots_jeux_videos[0]));
                } else if (strcmp(theme, "Animaux") == 0) {
                    jouer_jeu(mots_animaux, sizeof(mots_animaux) / sizeof(mots_animaux[0]));
                } else if (strcmp(theme, "Pays") == 0) {
                    jouer_jeu(mots_pays, sizeof(mots_pays) / sizeof(mots_pays[0]));
                }
                break;
            case 2:
                definir_taille_grille();
                break;
            case 3:
                ajouter_liste_mots();
                break;
            case 4:
                sortie_jeu = 1;
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}

void definir_taille_grille() {
    printf("Entrez la taille de la grille (max %d): ", TAILLE_GRILLE_MAX);
    scanf("%d", &TAILLE_GRILLE);
    if (TAILLE_GRILLE > TAILLE_GRILLE_MAX) {
        TAILLE_GRILLE = TAILLE_GRILLE_MAX;
    } else if (TAILLE_GRILLE < 5) {
        TAILLE_GRILLE = 5;
    }
    printf("Taille de la grille definie a %d\n", TAILLE_GRILLE);
    system("pause");
}

void ajouter_liste_mots() {
    int nb_mots;
    printf("Combien de mots voulez-vous ajouter? ");
    scanf("%d", &nb_mots);

    char **nouvelle_liste_mots = malloc(nb_mots * sizeof(char*));
    char mot[50];

    for (int i = 0; i < nb_mots; i++) {
        printf("Entrez le mot %d: ", i + 1);
        scanf("%s", mot);
        nouvelle_liste_mots[i] = strdup(mot);
    }

    jouer_jeu(nouvelle_liste_mots, nb_mots);

    for (int i = 0; i < nb_mots; i++) {
        free(nouvelle_liste_mots[i]);
    }
    free(nouvelle_liste_mots);
}

void confirmer_sortie(int *sortie_jeu) {
    printf("\n");
    printf("Appuyez sur 'q' pour quitter au menu principal, ou sur une autre touche pour continuer le jeu.");
    char ch = getch();
    if (ch == 'q') {
        *sortie_jeu = 0;
    } else {
        *sortie_jeu = 1;
    }
}