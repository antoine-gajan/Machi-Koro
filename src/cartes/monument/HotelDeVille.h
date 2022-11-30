#ifndef SRC_HOTELDEVILLE_H
#define SRC_HOTELDEVILLE_H

#include "Monument.h"

class HotelDeVille : public Monument {
public :
    //*** Constructeur et destructeur ***//
    HotelDeVille();
    ~HotelDeVille()=default;

    //*** Méthodes ***//
    virtual std::string get_name() const {return "HotelDeVille";}
};

#endif //SRC_HOTELDEVILLE_H
