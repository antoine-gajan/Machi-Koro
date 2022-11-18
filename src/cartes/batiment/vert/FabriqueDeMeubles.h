#ifndef MACHI_KORO_FABRIQUE_DE_MEUBLES_H
#define MACHI_KORO_FABRIQUE_DE_MEUBLES_H

#include "../Batiment.h"

class FabriqueDeMeubles : public Batiment {
public:
    FabriqueDeMeubles(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_FABRIQUE_DE_MEUBLES_H
