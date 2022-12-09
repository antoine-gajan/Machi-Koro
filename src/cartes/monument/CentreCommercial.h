#ifndef MACHI_KORO_CENTRECOMMERCIAL_H
#define MACHI_KORO_CENTRECOMMERCIAL_H

#include "Monument.h"

class CentreCommercial : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        CentreCommercial();
        ~CentreCommercial()override=default;
        CentreCommercial(const CentreCommercial& centreCommercial) = default;
        CentreCommercial* clone() const override {return new CentreCommercial(*this);};

        //*** Methodes ***//
        void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_CENTRECOMMERCIAL_H
