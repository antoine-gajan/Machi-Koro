#ifndef MACHI_KORO_AEROPORT_H
#define MACHI_KORO_AEROPORT_H

#include "Monument.h"

class Aeroport : public Monument {
    public:
        //*** Constructeur et destructeur ***//
        Aeroport();
        ~Aeroport()=default;

        //*** Méthodes ***//
        std::string get_name() const {return "Aeroport";}
        void declencher_effet() const;
};

#endif //MACHI_KORO_AEROPORT_H
