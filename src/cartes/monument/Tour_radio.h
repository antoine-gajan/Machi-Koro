#ifndef MACHI_KORO_TOUR_RADIO_H
#define MACHI_KORO_TOUR_RADIO_H

#include "Monument.h"
#include "../../Joueur/Joueur.h"

class Tour_radio : public Monument {
    public:
        Tour_radio(const string& path_image);
        ~Tour_radio()=default;

        void effet(const Joueur& joueur);
};

#endif //MACHI_KORO_TOUR_RADIO_H
