//
// Created by Ewan on 27/06/2024.
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

void afficher_menu() {
    system("cls");
    printf("Menu Principal:\n");
    printf("1. Choisir un theme\n");
    printf("2. Choisir la taille de la grille\n");
    printf("3. Ajouter une nouvelle liste de mots\n");
    printf("4. Quitter le jeu\n");
}

int selection() {
    char touche = _getch();
    switch (touche) {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        default: return -1;
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
        afficher_menu();
        choix = selection();

        switch (choix) {
            case 1:
                choisir_theme(theme);
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
                quitter();
                sortie_jeu = 1;
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}


void confirmer_sortie(int *sortie_jeu) {
    printf("\n");
    printf("Appuyez sur 'Esc' pour quitter au menu principal, ou sur une autre touche pour continuer le jeu.");
    char ch = getch();
    if (ch == 27 ) {
        *sortie_jeu = 0;
    } else {
        *sortie_jeu = 1;
    }
}

void quitter() {
    printf("Fermeture dans 5 secondes\n");
    fflush(stdout);

    for (int i = 4; i >= 0; --i) {
        Sleep(1000);
        printf("%d\n", i);
        fflush(stdout);
    }

    printf("\n");
    exit(0);
}
