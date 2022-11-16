#ifndef MACHI_KORO_MONUMENT_H
#define MACHI_KORO_MONUMENT_H

#include "carte.h"
#include <iostream>
using namespace std;

enum Moment_Effet {AVANT, PENDANT, APRES};

class Monument : public Carte {

    private:
    Moment_Effet moment;

    Monument(Moment_Effet moment, string nom, unsigned int prix, string description_effet, string path_image);
    ~Monument() {delete this;} // pas sûr ici pour l'appel du destructeur de cartes ?

    public:
    const Moment_Effet getMoment() const {return moment;}
};

#endif //MACHI_KORO_MONUMENT_H
