#ifndef MACHI_KORO_UTILS_H
#define MACHI_KORO_UTILS_H

#include "../Joueur/Joueur.h"
#include "../cartes/batiment/Batiment.h"
#include <string>

unsigned int count_type(Joueur *joueur, string type);

// entier valide entre 0 et tab_joueurs.size() - 1, ne doit pas etre egal a joueur_actuel
unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);


// séléction d'un batiment chez un joueur (selection d'un pointeur sa paire map<batiment, nb>)
// map est le dictionnaire entier, pair est une paire en particulier (paire->first et paire->second)
// on ne fait pas de const pair car on peut etre ammené a la modifier par la suite en cas d'échange de carte
pair<Batiment*, unsigned int>* selectionner_batiment(Joueur *joueur);



#endif //MACHI_KORO_UTILS_H
