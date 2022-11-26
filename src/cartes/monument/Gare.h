#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H

#include "Monument.h"
#include "Joueur.h"

class Gare : public Monument {
public :
    //*** Constructeur et destructeur ***//
    Gare();
    ~Gare()=default;

    //*** Méthodes ***//
    virtual string get_name() const {return "Gare";}
};

#endif //MACHI_KORO_GARE_H
