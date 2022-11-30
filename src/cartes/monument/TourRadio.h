#ifndef MACHI_KORO_TOURRADIO_H
#define MACHI_KORO_TOURRADIO_H

#include "Monument.h"

class TourRadio : public Monument {
    public:
        //*** Constructeur et destructeur ***//
        TourRadio();
        ~TourRadio()=default;

        //*** Méthodes ***//
        void declencher_effet() const;
};

#endif //MACHI_KORO_TOURRADIO_H
