#ifndef MACHI_KORO_CENTRECOMMERCIAL_H
#define MACHI_KORO_CENTRECOMMERCIAL_H

#include "Monument.h"

class CentreCommercial : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        CentreCommercial();
        ~CentreCommercial()=default;

        //*** Methodes ***//
        void declencher_effet() const;
};

#endif //MACHI_KORO_CENTRECOMMERCIAL_H
