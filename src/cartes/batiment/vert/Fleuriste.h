#ifndef MACHI_KORO_FLEURISTE_H
#define MACHI_KORO_FLEURISTE_H

#include "../Batiment.h"

class Fleuriste : public Batiment {
public:
    Fleuriste(const string& path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_FLEURISTE_H
