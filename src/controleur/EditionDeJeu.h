#ifndef MACHI_KORO_EDITIONDEJEU_H
#define MACHI_KORO_EDITIONDEJEU_H

#include <string>
#include <map>
#include <vector>
#include "Batiment.h"
#include "Monument.h"

class EditionDeJeu{
protected:
    std::string nom;
    unsigned int nb_joueurs_min;
    unsigned int nb_joueurs_max;
    unsigned int nb_monuments_win;
    map<Batiment*, unsigned int> batiments;
    map<Monument*, unsigned int> monuments;
    bool est_edition;
    EditionDeJeu(string& nom, unsigned int joueurs_min, unsigned int joueurs_max, unsigned int mon_win, Monument* list_mon[], unsigned int quantite_mon[], Batiment* list_bat[], unsigned int quantite_bat[], bool edition);
    ~EditionDeJeu()=default;
public:
    const std::string& get_nom() const {return nom;};
    unsigned int get_nb_joueurs_min() const {return nb_joueurs_min;};
    unsigned int get_nb_joueurs_max() const {return nb_joueurs_max;};
    unsigned int get_nb_monuments_win() const {return nb_monuments_win;};
    bool get_est_edition() const {return est_edition;};
};
#endif //MACHI_KORO_EDITIONDEJEU_H
