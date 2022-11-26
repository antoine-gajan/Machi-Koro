#ifndef MACHI_KORO_PORT_H
#define MACHI_KORO_PORT_H

#include "Monument.h"
#include "Joueur.h"

class Port : public Monument {
    public :
        //*** Constructeur et destructeur ***//
        Port();
        ~Port()=default;

        //*** Méthodes ***//
        virtual string get_name() const {return "Port";}
};


#endif //MACHI_KORO_PORT_H
