#ifndef MACHI_KORO_PARCATTRACTION_H
#define MACHI_KORO_PARCATTRACTION_H

#include "Monument.h"

class ParcAttraction : public Monument {
public:
    //*** Constructeur et destructeur ***//
    ParcAttraction();
    ~ParcAttraction()=default;

    //*** Méthodes ***//
    virtual std::string get_name() const {return "ParcAttraction";}
    virtual void declencher_effet() const;
};


#endif //MACHI_KORO_PARCATTRACTION_H
