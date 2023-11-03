#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Inclure la biblioth�que string.h
#include "film.h"


/*Fonction qui test l'existence du fichier avec le nom donn�, le cr�� s'il n'existe pas*/
FILE* creation_fichier(const char* nomFichier)
{
	FILE* fichier = fopen(nomFichier, "r"); //ouvre le fichier en lecture seule, le fichier doit exister pour que cela fonctionne

	if (fichier == NULL)
	{
		//le fichier n'existe pas, il faut le cr�er
		fichier = fopen(nomFichier, "w"); //ouverture en �criture seule, ce qui cr�� le fichier s'il n'existe pas

		//Tester si l'operation a fonctionn�
		if (fichier != NULL)
		{
			//le fichier a �t� cr�� avec succ�s, on le ferme
			fclose(fichier);
		}
		else
		{
			//erreur lors de la cr�ation du fichier
			perror("Erreur lors de la cr�ation du fichier\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		//le fichier existe, on le ferme
		fclose(fichier);
	}
	return fichier;
}

/*Fonction d'initialisation de la liste chainee*/
Liste* init_liste()
{
	//on cree la liste et on alloue de la memoire dynamique
	Liste* liste = malloc(sizeof(*liste));

	//On verifie que l'allocation a fonctionn�
	if (liste == NULL)
	{
		perror("Erreur d'allocation memoire.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		liste->premier = NULL;
	}
	return liste;
}

/*
//Fonction qui ajoute un bloc Film � la liste chainee
void insertion_film(Liste* liste, FilmNode film)
{

	//Verification de la creation du bloc
	if (nouveauFilm == NULL)
	{
		perror("Erreur d'allocation memoire.\n");
		exit(EXIT_FAILURE);
	}
	else
	{


	}

}
*/

/*Fonction qui parcourt tout le fichier texte et stocke les data dans une liste chainee*/
void lecture_fichier(FILE* fichier, Film film[10])
{

}
