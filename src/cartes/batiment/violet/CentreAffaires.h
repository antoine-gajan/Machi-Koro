#ifndef MACHI_KORO_CENTREAFFAIRES_H
#define MACHI_KORO_CENTREAFFAIRES_H

#include "../Batiment.h"
#include <list>
class CentreAffaires : public Batiment {
public:
    CentreAffaires(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_CENTREAFFAIRES_H
