#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <vector>
#include "EditionDeJeu.h"
#include "Joueur.h"

class Partie {
private:
    vector<Joueur*> tab_joueurs;
    Joueur* joueur_actuel;
    unsigned int nb_monuments_win;
    unsigned int nb_joueurs;
public:
    void jouer_partie();
    void jouer_tour(Joueur* joueur_actuel);
    Partie(vector<EditionDeJeu*> editions);
    ~Partie() = default;
};

#endif //MACHI_KORO_PARTIE_H
