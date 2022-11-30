#ifndef SRC_FABRIQUEDUPERENOEL_H
#define SRC_FABRIQUEDUPERENOEL_H

#include "Monument.h"

class FabriqueDuPereNoel : public Monument {
public :
    //*** Constructeur et destructeur ***//
    FabriqueDuPereNoel();
    ~FabriqueDuPereNoel()=default;

    //*** Méthodes ***//
    std::string get_name() const {return "FabriqueDuPereNoel";}
    void declencher_effet() const;
};

#endif //SRC_FABRIQUEDUPERENOEL_H
