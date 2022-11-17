#ifndef MACHI_KORO_PIOCHE_H
#define MACHI_KORO_PIOCHE_H

#include <vector>
#include <random>
#include <algorithm>
#include "../cartes/batiment/Batiment.h"

class Pioche {
    private:
        std::vector<Batiment *> contenu;

    public:
        Pioche(Batiment *batiments[]);
        ~Pioche() {contenu.clear();};
        Batiment* getCarte() {return contenu.front();}; // retourne la carte du dessus de la pioche
        void melanger() {std::random_shuffle(contenu.begin(), contenu.end());}; // mélange la pioche
        bool est_vide() {return contenu.empty();}; // vérifie si la pioche est vide
};

#endif //MACHI_KORO_PIOCHE_H
