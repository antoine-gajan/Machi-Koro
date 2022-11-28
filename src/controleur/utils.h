#ifndef MACHI_KORO_UTILS_H
#define MACHI_KORO_UTILS_H

#include "../Joueur/Joueur.h"
#include "../cartes/batiment/Batiment.h"
#include <string>

// Compte le nombre de cartes d'un type donné dans le jeu d'un Joueur
unsigned int count_type(Joueur *joueur, const string& type);

// Renvoie l'indice d'un joueur entier valide different de l'indice du joueur actuel
unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);


// séléction d'un batiment chez un joueur, on fait choisir parmis la liste des batiments possédés par le joueur
// on renvoit un simple pointeur sur le batiment (qui lui n'est pas spécifique au joueur)
Batiment* selectionner_batiment(Joueur *joueur);

// idem mais pour monument
Monument* selectionner_monument(Joueur *joueur);

// Fonction qui retourne une liste des monuments non violets possédé par un joueur
map<Batiment*, unsigned int> get_liste_bat_non_special(Joueur* j);

//Fonction qui échange le batiment 1 du joueur 1 avec le batiment 2 du joueur 2
void swap_bat_players(Joueur *j1, Joueur *j2, Batiment *bat1, Batiment *bat2);




#endif //MACHI_KORO_UTILS_H
