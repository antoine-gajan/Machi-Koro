#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H
#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Gare : public Monument {
public :
    Gare(const string& path_image);

    ~Gare()=default;
    void effet(const Joueur& joueur);
};

#endif //MACHI_KORO_GARE_H
