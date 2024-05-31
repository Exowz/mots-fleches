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

