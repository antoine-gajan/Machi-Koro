#ifndef MACHI_KORO_CENTRECOMMERCIAL_H
#define MACHI_KORO_CENTRECOMMERCIAL_H

#include "Monument.h"

class CentreCommercial : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        CentreCommercial();
        ~CentreCommercial()=default;

        //*** Méthodes ***//
        std::string get_name() const {return "CentreCommercial";}
        void declencher_effet() const;
};

#endif //MACHI_KORO_CENTRECOMMERCIAL_H
