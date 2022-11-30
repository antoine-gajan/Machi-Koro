#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <list>
#include "EditionDeJeu/EditionDeJeu.h"
#include "Joueur.h"
#include "Shop.h"
#include "Pioche.h"

class Partie {
private:
    list<Joueur*> tab_joueurs;
    Joueur* joueur_actuel;
    unsigned int nb_monuments_win;
    Shop shop;
    Pioche pioche;
    vector<EditionDeJeu*> editions;

public:
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour(Joueur* joueur_actuel);
    bool est_gagnant(Joueur *joueur);

    //********** Constructeurs et getters **********//
    Partie(vector<Joueur*> liste_joueurs, vector<EditionDeJeu*> editions);
    Joueur* get_joueur_actuel() const {return joueur_actuel;};
    ~Partie() = default;
};

#endif //MACHI_KORO_PARTIE_H
