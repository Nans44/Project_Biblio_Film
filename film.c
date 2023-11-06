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


//Fonction qui ajoute un bloc Film � la liste chainee
void insertion_film(Liste* liste, Film film)
{
	//Creation et allocation m�moire du nouveau bloc
	FilmNode* nouveauFilm = malloc(sizeof(FilmNode));

	//Verification de la creation du bloc
	if (nouveauFilm == NULL)
	{
		perror("Erreur d'allocation memoire.\n");
		exit(EXIT_FAILURE);
	}

	nouveauFilm->film.note = film.note;

	if (nouveauFilm->film.nom == NULL) {
		perror("Erreur lors de la copie du nom du film\n");
		exit(EXIT_FAILURE);
	}
	//strcpy pour copier des chaines de caracteres, ici nom du film
	strcpy(nouveauFilm->film.nom, film.nom);

	//Initialisation du prochain noeud � NULL
	nouveauFilm->suivant = NULL;

	//Si la liste est vide, le nouveau noeud devient le premier noeud
	if (liste->premier == NULL)
	{
		liste->premier = nouveauFilm;
	}

	else
	{
		//sinon on ajoute le nouveau film � la fin de la liste
		FilmNode* courant = liste->premier;
		while (courant->suivant != NULL)
		{
			courant = courant->suivant;
		}
		courant->suivant = nouveauFilm;
	}

}

void afficher_liste_chainee(Liste* liste)
{
	//On v�rifie si la liste est nulle
	if (liste == NULL)
	{
		perror("La liste est nulle \n");
		exit(EXIT_FAILURE);
	}

	//On cr�� un pointeur de FilmNode qui va parcourir tous les films cr��s en commen�ant par le premier
	if (liste->premier == NULL)
	{
		printf("La liste est vide\n");
		exit(EXIT_FAILURE);
	}

	FilmNode* courant = liste->premier;
	//tant qu'on n'a pas atteint la fin de la liste
	while (courant != NULL)
	{
		printf("%s\n", courant->film.nom);
		printf("%d\n", courant->film.note);
		courant = courant->suivant;
	}
}


/*Fonction qui parcourt tout le fichier texte et stocke les data dans une liste chainee*/
void lecture_fichier(FILE* fichier, Film film[10])
{

}
