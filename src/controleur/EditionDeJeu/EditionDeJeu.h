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

    vector<Monument> mon;
    map<Batiment, unsigned int> bat;

    bool est_edition;

public:
    /// *** Constructeur et destructeur *** ///
    EditionDeJeu(const string& nom);
    EditionDeJeu() = default;
    ~EditionDeJeu()=default;

    /// *** Getters *** ///
    const std::string& get_nom() const {return nom;};
    unsigned int get_nb_joueurs_min() const {return nb_joueurs_min;};
    unsigned int get_nb_joueurs_max() const {return nb_joueurs_max;};
    unsigned int get_nb_monuments_win() const {return nb_monuments_win;};
    bool get_est_edition() const {return est_edition;};
};
#endif //MACHI_KORO_EDITIONDEJEU_H
