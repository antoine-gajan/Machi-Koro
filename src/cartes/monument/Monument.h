#ifndef MACHI_KORO_MONUMENT_H
#define MACHI_KORO_MONUMENT_H

#include "Carte.h"
#include "Joueur.h"

enum Moment_Effet {AVANT, PENDANT, APRES};

class Monument : public Carte{
    protected:
        Moment_Effet moment;

    public:
        //*** Constructeur et destructeur ***//
        Monument(Moment_Effet moment, const string& nom, unsigned int prix, const string& description_effet, const string& path_image);
        ~Monument()=default;

        //*** GETTER ***//
        virtual string get_type() const {return "Monument";};
        virtual string get_name() const = 0;
        Moment_Effet getMoment() const {return moment;}

        //*** SETTER ***//
        void set_image(const string& new_path) {path_image = new_path;}
};

#endif //MACHI_KORO_MONUMENT_H
