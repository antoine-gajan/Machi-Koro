#ifndef MACHI_KORO_PARC_ATTRACTION_H
#define MACHI_KORO_PARC_ATTRACTION_H

#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Parc_attraction : public Monument {
public:
    Parc_attraction(const string& path_image);
    ~Parc_attraction()=default;

    void effet(Joueur* joueur);
};


#endif //MACHI_KORO_PARC_ATTRACTION_H
