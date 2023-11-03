#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Inclure la bibliothèque string.h
#include "film.h"

#define MAX_STRING_LENGTH 80 // Utilisez un nom unique

Film films[10];


int main()
{
    //creation du fichier
    FILE* fichier = creation_fichier("Films_Nono.txt");

    //creation de la liste chainee
    Liste* maliste = init_liste();

    //ESSAI : on stocke le nom du film dans le tableau, lecture depuis le fichier txt
    int index = 0; //pour parcourir le tableau
    char temp[MAX_STRING_LENGTH]; //tableau de caracteres temporaire pour stocker chaque ligne

    char delim[] = ",";

    fichier = fopen("Films_Nono.txt", "r");
    //utilisation de fgets qui lit un fichier plutôt que l'entrée clavier, une ligne à la fois
    while (fgets(temp, MAX_STRING_LENGTH, fichier) != NULL)
    {
        int compteur = 0;
        char* p = strtok(temp, delim);

        while (p != NULL) //tant qu'il existe encore des virgules
        {
            printf("%s\n", p);

            switch (compteur)
            {
                case 0:
                    strcpy(films[index].nom, p);
                    break;
                case 1:
                    films[index].note = atoi(p);
                    break;
                default:
                    break;
            }
            p = strtok(NULL, delim);
            compteur++;
        }
        printf("Nom du film %d : %s, note : %d\n", index+1, films[index].nom, films[index].note);
        index++;
    }

    fclose(fichier);

    return 0;
}
