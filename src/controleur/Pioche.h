#ifndef MACHI_KORO_PIOCHE_H
#define MACHI_KORO_PIOCHE_H

#include <vector>
#include <random>
#include <stack>
#include <algorithm>
#include "Batiment.h"

class Pioche {
    friend class Batiment;

    private:
        std::stack<Batiment *> contenu;

    public:
        Pioche(const vector<Batiment*>& batiments);
        ~Pioche();
        Batiment* getCarte() {return contenu.pop();}; // retourne la carte du dessus de la pioche
        void melanger() {std::random_shuffle(contenu.begin(), contenu.end());}; // mélange la pioche
        bool est_vide() {return contenu.empty();}; // vérifie si la pioche est vide
};

#endif //MACHI_KORO_PIOCHE_H
