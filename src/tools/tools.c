//
// Created by Ewan Kapoor on 28/05/2024.
//

#include "tools.h"

void clignoter_logo() {
    for(int i = 0; i > 0; i++) {
        sleep(500); // Attendre à nouveau 500 millisecondes
        system("cls"); // Effacer l'écran
        //Fonction à créer pour le logo
        sleep(500); // Attendre à nouveau 500 millisecondes
        system("cls"); // Effacer l'écran
    }
}

void COULEUR(int couleurDuTexte,int couleurDeFond) { // Change la couleur du texte
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE); // On récupère le handle de la console
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte); // On change la couleur du texte
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE));
}

void definir_couleur(int couleur) {
    switch (couleur) {
        case 0: // Damier vert clair et gris clair
            printf("\033[102m\033[30m");
            break;
        case 1: // Curseur cyan
            printf("\033[46m\033[30m");
            break;
        case 2: // Sélection
            printf("\033[40m\033[31m");
            break;
        case 3: // Validé
            printf("\033[42m\033[30m");
            break;
    }
}

void positionner_curseur(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}
