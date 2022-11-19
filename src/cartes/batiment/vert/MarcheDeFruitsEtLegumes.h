#ifndef MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
#define MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H

#include "../Batiment.h"

class MarcheDeFruitsEtLegumes : public Batiment {
public:
    MarcheDeFruitsEtLegumes(const string& path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
