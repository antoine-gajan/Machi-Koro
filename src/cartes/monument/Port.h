#ifndef MACHI_KORO_PORT_H
#define MACHI_KORO_PORT_H

#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Port : public Monument {
    public :
        Port(const string& path_image);

        ~Port()=default;
        void effet(const Joueur& joueur);
};


#endif //MACHI_KORO_PORT_H
