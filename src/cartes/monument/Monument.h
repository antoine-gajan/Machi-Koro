#ifndef MACHI_KORO_MONUMENT_H
#define MACHI_KORO_MONUMENT_H

#include "../Carte.h"
#include <iostream>
using namespace std;

enum Moment_Effet {AVANT, PENDANT, APRES};

class Monument  {
    protected:
        Moment_Effet moment;

    public:
        Monument(Moment_Effet moment, string nom, unsigned int prix, string description_effet, string path_image);
        const Moment_Effet getMoment() const {return moment;}
        ~Monument()=default;

};

#endif //MACHI_KORO_MONUMENT_H
