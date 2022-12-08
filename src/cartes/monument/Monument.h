#ifndef MACHI_KORO_MONUMENT_H
#define MACHI_KORO_MONUMENT_H

#include "Carte.h"

enum Moment_Effet {AVANT, PENDANT, APRES};

class Monument : public Carte{
    protected:
        Moment_Effet moment;

    public:
        //*** Constructeur et destructeur ***//
        Monument(Moment_Effet moment, const std::string& nom, unsigned int prix, const std::string& description_effet, const std::string& path_image);
        ~Monument()override=default;
        virtual Monument* clone() const = 0;

        //*** GETTER ***//
        const std::string& get_type() const override {return "Monument";};
        Moment_Effet getMoment() const {return moment;}

        //*** SETTER ***//
        void set_image(const std::string& new_path) {path_image = new_path;}
};

#endif //MACHI_KORO_MONUMENT_H
