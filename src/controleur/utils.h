#ifndef MACHI_KORO_UTILS_H
#define MACHI_KORO_UTILS_H

#include "../Joueur/Joueur.h"
#include "../cartes/batiment/Batiment.h"
#include <string>

unsigned int count_type(Joueur *joueur, string type);

// entier valide entre 0 et tab_joueurs.size() - 1, ne doit pas etre egal a joueur_actuel
unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);


// séléction d'un batiment chez un joueur, on fait choisir parmis la liste des batiments possédés par le joueur
// on renvoit un simple pointeur sur le batiment (qui lui n'est pas spécifique au joueur)
Batiment* selectionner_batiment(Joueur *joueur);

// idem mais pour monument
Monument* selectionner_monument(Joueur *joueur);



#endif //MACHI_KORO_UTILS_H
