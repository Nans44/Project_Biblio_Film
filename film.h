#ifndef FILM_H
#define FILM_H

#define MAX_STRING_LENGTH 80 

/* Structure du film */
typedef struct Film Film;
struct Film
{
    char nom[MAX_STRING_LENGTH];
    int note;
    /*
    char real[MAX_STRING_LENGTH];
    char genre[MAX_STRING_LENGTH];
    char date_vue[MAX_STRING_LENGTH];
    unsigned int annee_sortie;
    */
};

/* Structure du film au sein de la liste chainée, càd données + pointeur */
typedef struct FilmNode FilmNode;
struct FilmNode
{
    Film film;
    FilmNode* suivant;
};

/*Structure de controle liste chainee*/
typedef struct Liste Liste;
struct Liste
{
    FilmNode* premier; //pointe sur le premier film
};

FILE* creation_fichier(const char* nomFichier); //fonction qui cree un fichier s'il n'existe pas, rien sinon
Liste* init_liste(); //fonction d'initialisation de la liste chainee
void insertion_film(Liste* liste, Film film); //ajoute un bloc film à la liste chainee
void afficher_liste_chainee(Liste* liste); //fonction qui print la liste chainee sur la sortie
void lecture_fichier(FILE* fichier); //fonction qui lit le fichier texte et stocke les variables dans la liste chainee


#endif // !FILM_H
