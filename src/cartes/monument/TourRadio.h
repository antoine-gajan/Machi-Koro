#ifndef MACHI_KORO_TOURRADIO_H
#define MACHI_KORO_TOURRADIO_H

#include "Monument.h"
#include "Joueur.h"

class TourRadio : public Monument {
    public:
        //*** Constructeur et destructeur ***//
        TourRadio();
        ~TourRadio()=default;

        //*** Méthodes ***//
        virtual string get_name() const {return "TourRadio";}
};

#endif //MACHI_KORO_TOURRADIO_H
