#ifndef MACHI_KORO_PARCATTRACTION_H
#define MACHI_KORO_PARCATTRACTION_H

#include "Monument.h"

class ParcAttraction : public Monument {
public:
    //*** Constructeur et destructeur ***//
    ParcAttraction();
    ~ParcAttraction()=default;

    //*** Méthodes ***//
    std::string get_name() const {return "ParcAttraction";}
    void declencher_effet() const;
};


#endif //MACHI_KORO_PARCATTRACTION_H
