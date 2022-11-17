#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H
#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Gare : public Monument {
public :
    Gare(string path_image);

    ~Gare()=default;
    void effet(Joueur *joueur);
};

#endif //MACHI_KORO_GARE_H
