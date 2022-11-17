#ifndef MACHI_KORO_STADE_H
#define MACHI_KORO_STADE_H

#include "../Batiment.h"

class Stade : public Batiment {
public:
    Stade(string nom, unsigned int prix, string description_effet, string path_image, couleur_bat coul, std::list<unsigned int> num, std::string type_bat);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_STADE_H
