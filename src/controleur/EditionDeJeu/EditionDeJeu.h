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
    vector<Monument*> monuments;
    bool est_edition;

public:
    EditionDeJeu(const string& nom, unsigned int joueurs_min, unsigned int joueurs_max, unsigned int mon_win, vector<Monument*> monuments, map<Batiment*, unsigned int> batiments, bool edition);
    EditionDeJeu() = default;
    ~EditionDeJeu()=default;
    const std::string& get_nom() const {return nom;};
    unsigned int get_nb_joueurs_min() const {return nb_joueurs_min;};
    unsigned int get_nb_joueurs_max() const {return nb_joueurs_max;};
    unsigned int get_nb_monuments_win() const {return nb_monuments_win;};
    bool get_est_edition() const {return est_edition;};
    map<Batiment*, unsigned int> get_batiments() const {return batiments;};
    vector<Monument*> get_monuments() const {return monuments;};
};
#endif //MACHI_KORO_EDITIONDEJEU_H
