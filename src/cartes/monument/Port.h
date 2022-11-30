#ifndef MACHI_KORO_PORT_H
#define MACHI_KORO_PORT_H

#include "Monument.h"

class Port : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        Port();
        ~Port()=default;

        //*** Méthodes ***//
        virtual std::string get_name() const {return "Port";}
        virtual void declencher_effet() const;
};


#endif //MACHI_KORO_PORT_H
