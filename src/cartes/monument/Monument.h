#ifndef MACHI_KORO_MONUMENT_H
#define MACHI_KORO_MONUMENT_H

#include "../Carte.h"
#include <iostream>
using namespace std;

enum Moment_Effet {AVANT, PENDANT, APRES};

class Monument : public Carte{
    protected:
        Moment_Effet moment;

    public:
        Monument(Moment_Effet moment, const string& nom, unsigned int prix, const string& description_effet, const string& path_image);
        Moment_Effet getMoment() const {return moment;}
        ~Monument()=default;

        virtual string get_type() const {return "Monument";};
};

#endif //MACHI_KORO_MONUMENT_H
