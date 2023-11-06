#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Inclure la bibliothèque string.h
#include "film.h"


/*Fonction qui test l'existence du fichier avec le nom donné, le créé s'il n'existe pas*/
FILE* creation_fichier(const char* nomFichier)
{
	FILE* fichier = fopen(nomFichier, "r"); //ouvre le fichier en lecture seule, le fichier doit exister pour que cela fonctionne

	if (fichier == NULL)
	{
		//le fichier n'existe pas, il faut le créer
		fichier = fopen(nomFichier, "w"); //ouverture en écriture seule, ce qui créé le fichier s'il n'existe pas

		//Tester si l'operation a fonctionné
		if (fichier != NULL)
		{
			//le fichier a été créé avec succès, on le ferme
			fclose(fichier);
		}
		else
		{
			//erreur lors de la création du fichier
			perror("Erreur lors de la création du fichier\n");
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

	//On verifie que l'allocation a fonctionné
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


//Fonction qui ajoute un bloc Film à la liste chainee
void insertion_film(Liste* liste, Film film)
{
	//Creation et allocation mémoire du nouveau bloc
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

	//Initialisation du prochain noeud à NULL
	nouveauFilm->suivant = NULL;

	//Si la liste est vide, le nouveau noeud devient le premier noeud
	if (liste->premier == NULL)
	{
		liste->premier = nouveauFilm;
	}

	else
	{
		//sinon on ajoute le nouveau film à la fin de la liste
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
	//On vérifie si la liste est nulle
	if (liste == NULL)
	{
		perror("La liste est nulle \n");
		exit(EXIT_FAILURE);
	}

	//On créé un pointeur de FilmNode qui va parcourir tous les films créés en commençant par le premier
	if (liste->premier == NULL)
	{
		printf("La liste est vide\n");
		exit(EXIT_FAILURE);
	}

	FilmNode* courant = liste->premier;
	//tant qu'on n'a pas atteint la fin de la liste
	printf("Voici la liste de vos films vus ainsi que leur note sur 5 : \n");
	printf("\n");
	while (courant != NULL)
	{
		printf("Film : %s\n", courant->film.nom);
		printf("Note : %d / 5\n", courant->film.note);
		printf("\n");
		courant = courant->suivant;
	}
}


/*Fonction qui parcourt tout le fichier texte et stocke les data dans une liste chainee*/
void lecture_fichier(FILE* fichier, Liste* maliste)
{
	//ESSAI : on stocke le nom du film dans le tableau, lecture depuis le fichier txt
	int index = 0; //pour parcourir le tableau
	char temp[MAX_STRING_LENGTH]; //tableau de caracteres temporaire pour stocker chaque ligne

	//creation d'un Film temp
	Film filmTemp;

	char delim[] = ",";

	//ouverture du fichier
	fichier = fopen("Films_Nono.txt", "r");

	//utilisation de fgets qui lit un fichier plutôt que l'entrée clavier, une ligne à la fois
	while (fgets(temp, MAX_STRING_LENGTH, fichier) != NULL)
	{
		int compteur = 0;
		char* p = strtok(temp, delim);

		while (p != NULL) //tant qu'il existe encore des virgules
		{
			//printf("%s\n", p);

			//permet de sélectionner quel élément est défini, délimité par une virgule
			switch (compteur)
			{
			case 0:
				strcpy(filmTemp.nom, p);
				break;
			case 1:
				filmTemp.note = atoi(p);
				break;
			default:
				break;
			}
			p = strtok(NULL, delim);
			compteur++;
		}
		//printf("Nom du film %d : %s, note : %d\n", index + 1, filmTemp.nom, filmTemp.note);
		insertion_film(maliste, filmTemp);
		index++;
	}
	//Fermeture du fichier
	fclose(fichier);

}

void entrer_nouveau_film(FILE* fichier, Liste* maliste)
{
	Film nouveauFilm;
	printf("Vous avez choisi d'ajouter un nouveau film vu ! \n");
	printf("Entrez le nom du film : \n");
	//limite la saisie à 79 caractères pour éviter les dépassements de tampon, et en lisant toute la ligne sans se soucier des espaces
	if (scanf(" %79[^\n]", nouveauFilm.nom) != 1)
	{
		perror("Erreur de saisie du nom du film\n");
		return;
	}

	//pour consommer le caractère de nouvelle ligne restant dans le tampon
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Entrez la note sur 5 à ce film : \n");
	if (scanf("%d", &nouveauFilm.note) != 1)
	{
		perror("Erreur de saisie de la note du film\n");
		return;
	}

	insertion_film(maliste, nouveauFilm);

	ecriture_nouveau_film(fichier, nouveauFilm);
}

void ecriture_nouveau_film(FILE* fichier, Film nouveauFilm)
{
	//ouverture du fichier, mode d'ouverture "a" pour append
	fichier = fopen("Films_Nono.txt", "a");
	if (fichier == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier en mode append.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fichier, "%s, %d", nouveauFilm.nom, nouveauFilm.note);
	fprintf(fichier,"\n");

	fclose(fichier);
}

int interface_ihm(FILE* fichier, Liste* liste)
{
	char c;
	printf("Que voulez-vous faire ?\n");
	printf("Entrez '+' pour ajouter un nouveau film, 'a' pour afficher vos films, q pour quitter le programme : \n");
	scanf("%c", &c);

	if (c == 'q')
	{
		printf("Fermeture du programme \n");
		return 0;
	}
	else
	{
		if (c == '+')
		{
			entrer_nouveau_film(fichier, liste);
		}

		else if (c == 'a')
		{
			afficher_liste_chainee(liste);
		}
		//pour consommer le caractère de nouvelle ligne restant dans le tampon
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		return 1;
	}
}

