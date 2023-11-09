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

/* Structure du film au sein de la liste chain�e, c�d donn�es + pointeur */
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
void insertion_film(Liste* liste, Film film); //ajoute un bloc film � la liste chainee
void afficher_liste_chainee(Liste* liste); //fonction qui print la liste chainee sur la sortie
void lecture_fichier(FILE* fichier, Liste* maliste); //fonction qui lit le fichier texte et stocke les variables dans la liste chainee
void entrer_nouveau_film(FILE* fichier, Liste* maliste);//fonction qui demande � l'utilisateur d'ajouter un film (nom + note) et l'ajoute � la liste chainee + �crit dans le fichier texte le nouveau film
void ecriture_nouveau_film(FILE* fichier, Film nouveauFilm);//fonction qui �crit le nouveau film dans le fichier texte
void changer_note_film(FILE* fichier, Liste* maliste); //permet de changer la note d'un film


int interface_ihm(FILE* fichier, Liste* maliste); //fonction qui va permettre � l'utilisateur de choisir ce qu'il veut faire (renvoie 0 pour quitter le programme)


#endif // !FILM_H
