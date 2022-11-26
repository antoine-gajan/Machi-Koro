#ifndef MACHI_KORO_PARCATTRACTION_H
#define MACHI_KORO_PARCATTRACTION_H

#include "Monument.h"
#include "Joueur.h"

class ParcAttraction : public Monument {
public:
    //*** Constructeur et destructeur ***//
    ParcAttraction();
    ~ParcAttraction()=default;

    //*** Méthodes ***//
    virtual string get_name() const {return "ParcAttraction";}
};


#endif //MACHI_KORO_PARCATTRACTION_H
