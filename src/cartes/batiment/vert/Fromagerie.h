#ifndef MACHI_KORO_FROMAGERIE_H
#define MACHI_KORO_FROMAGERIE_H

#include "../Batiment.h"

class Fromagerie : public Batiment {
public:
    Fromagerie(const string& path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_FROMAGERIE_H
