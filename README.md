# Project_Biblio_Film

PROJET DE BIBLIOTHEQUE DE FILMS


PRESENTATION ET ANALYSE DES BESOINS DU PROJET

Principe du projet : afin de tenir un journal des films vus, en leur attribuant une note sur 5, on souhaite créer un programme qui sauvegarde un film et ses caractéristiques dans un fichier texte. 
Le but de ce code N'EST PAS de faire quelque chose d'optimisé en langage C, mais plutôt de balayer tous les concepts étudiés pour en utiliser le plus possible au sein d'un même projet. D'autres projets du genre, plus optimisés,
seront réalisés dans d'autres langages plus adaptés (C++, Java, Python).

A chaque exécution du programme on veut :
-	Ajouter un film vu, avec son nom, la date du visionnage, le genre, l’année de sortie, et une note sur 5 attribuée par l’utilisateur
-	Modifier un film
-	Supprimer un film
-	Afficher la liste avec plusieurs modes de tri : 
	Par nom
	Par note
	Par date de visionnage
	Par année de sortie
	Par genre
-	(Optionnel) afficher des statistiques, comme la note moyenne, le genre préféré, etc…

Dans son implémentation actuelle, on souhaite utiliser les listes chaînées. Lors de la lecture du fichier texte, les films sont sauvegardées dans une liste chaînée, ce qui constitue notre principal lien.
