#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H

#include "Monument.h"

class Gare : public Monument {
public :
    //*** Constructeur et destructeur ***//
    Gare();
    ~Gare()=default;

    //*** Methodes ***//
    void declencher_effet() const;
};

#endif //MACHI_KORO_GARE_H
