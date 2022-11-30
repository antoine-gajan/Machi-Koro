#ifndef SRC_HOTELDEVILLE_H
#define SRC_HOTELDEVILLE_H

#include "Monument.h"

class HotelDeVille : public Monument {
public :
    //*** Constructeur et destructeur ***//
    HotelDeVille();
    ~HotelDeVille()=default;

    //*** Methodes ***//
    void declencher_effet() const;
};

#endif //SRC_HOTELDEVILLE_H
