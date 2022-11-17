#ifndef MACHI_KORO_AEROPORT_H
#define MACHI_KORO_AEROPORT_H

#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Aeroport : public Monument {
    public:
        Aeroport(string path_image);
        ~Aeroport()=default;

        void effet(Joueur *joueur);
};

#endif //MACHI_KORO_AEROPORT_H
