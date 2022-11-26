#ifndef MACHI_KORO_CENTRECOMMERCIAL_H
#define MACHI_KORO_CENTRECOMMERCIAL_H

#include "Monument.h"
#include "Joueur.h"

class CentreCommercial : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        CentreCommercial();
        ~CentreCommercial()=default;

        //*** Méthodes ***//
        virtual string get_name() const {return "CentreCommercial";}
};

#endif //MACHI_KORO_CENTRECOMMERCIAL_H
