#ifndef MACHI_KORO_SHOP_H
#define MACHI_KORO_SHOP_H

#include <map>
#include <vector>
#include "Batiment.h"

class Shop{
    private:
        unsigned int nb_tas_max;
        unsigned int nb_tas_reel;
        map<Batiment*, unsigned int> contenu;
    public:
        /**** Constructeur et destructeur ****/
        Shop(unsigned int nb_tas);
        ~Shop();

        /**** Getters ****/
        unsigned int get_nb_tas_max() const {return nb_tas_max;};
        unsigned int get_nb_tas_reel() const {return nb_tas_reel;};
        // const std::map<Batiment*, unsigned int>& get_contenu() {return contenu;};
        // const vector<Batiment*>& get_contenu() const;

        /**** Méthodes ****/
        void completer_shop(Batiment* new_bat);
        void affiche_shop();
        Batiment *acheter_batiment(Batiment* bat);
};

#endif //MACHI_KORO_SHOP_H
