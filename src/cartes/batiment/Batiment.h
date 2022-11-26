#ifndef MACHI_KORO_BATIMENT_H
#define MACHI_KORO_BATIMENT_H
#include <string>
#include <list>
#include "../Carte.h"
#include <iostream>

using namespace std;

enum couleur_bat {Bleu, Rouge, Vert, Violet};

class Batiment : public Carte {
    protected:
        couleur_bat couleur;
        list<unsigned int> num_activation;
        string type;
        Batiment(string nom, unsigned int prix, string description_effet, string path_image, couleur_bat coul, list<unsigned int> num, string type_bat);
        virtual ~Batiment() = default;

    public:
        couleur_bat get_couleur() const {return couleur;};
        list<unsigned int> get_num_activation() const {return num_activation;};
        string get_bat_type() const {return type;};
        virtual string get_type() const {return type;};

    virtual void declencher_effet() = 0;
};
#endif //MACHI_KORO_BATIMENT_H
