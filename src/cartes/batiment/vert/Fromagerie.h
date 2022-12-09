#ifndef MACHI_KORO_FROMAGERIE_H
#define MACHI_KORO_FROMAGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fromagerie : public Batiment {
public:
    Fromagerie();
    ~Fromagerie() override = default;
    Fromagerie(const Fromagerie& fromagerie) = default;
    Batiment* clone() const override {return new Fromagerie(*this);};
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_FROMAGERIE_H
