#ifndef MACHI_KORO_PORT_H
#define MACHI_KORO_PORT_H

#include "Monument.h"

class Port : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        Port();
        ~Port()=default;

        //*** Methodes ***//
        void declencher_effet() const;
};


#endif //MACHI_KORO_PORT_H
