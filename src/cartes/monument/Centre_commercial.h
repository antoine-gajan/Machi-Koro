#ifndef MACHI_KORO_CENTRE_COMMERCIAL_H
#define MACHI_KORO_CENTRE_COMMERCIAL_H

#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Centre_commercial : public Monument {
    public :
        Centre_commercial(const string& path_image);

        ~Centre_commercial()=default;
        unsigned int effet(unsigned int coup_init);
};

#endif //MACHI_KORO_CENTRE_COMMERCIAL_H
