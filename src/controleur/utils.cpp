#include "utils.h"


unsigned int count_type(Joueur *joueur, const string& type) {
    unsigned int count = 0;

    // pour chaque couleur de la liste de batissements du joueur
    map<string, map<Batiment*, unsigned int>>::iterator it;
    for (it=joueur->get_liste_batiment().begin(); it!=joueur->get_liste_batiment().end(); ++it) {

        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        map<Batiment*, unsigned int>::iterator it2;
        for (it2=it->second.begin(); it2!=it->second.end(); ++it2) {
            if (it2->first->get_type() == type) {
                count += it2->second;
            }
        }
    }

    return count;
}