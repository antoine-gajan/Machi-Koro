#ifndef MACHI_KORO_GARE_H
#define MACHI_KORO_GARE_H

#include "Monument.h"

class Gare : public Monument {
public :
    //*** Constructeur et destructeur ***//
    Gare();
    ~Gare()=default;

    //*** Méthodes ***//
    virtual std::string get_name() const {return "Gare";}
    virtual void declencher_effet() const;
};

#endif //MACHI_KORO_GARE_H
