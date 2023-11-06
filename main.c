#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Inclure la bibliothèque string.h
#include "film.h"

#define MAX_STRING_LENGTH 80 // Utilisez un nom unique


int main()
{
    //creation du fichier
    FILE* fichier = creation_fichier("Films_Nono.txt");

    //creation de la liste chainee
    Liste* maliste = init_liste();

    lecture_fichier(fichier, maliste);
    afficher_liste_chainee(maliste);

    entrer_nouveau_film(fichier, maliste);

    afficher_liste_chainee(maliste);

    return 0;
}
