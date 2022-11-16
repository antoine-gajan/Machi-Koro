#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H
#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Gare : public Monument {
public :
    Gare(Moment_Effet effet_moment, string nom, unsigned int prix, string description_effet, string path_image);

    ~Gare()=default;
    void effet(Joueur *joueur);
};

#endif //MACHI_KORO_GARE_H
