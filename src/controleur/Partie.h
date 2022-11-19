#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <vector>
#include "EditionDeJeu.h"
#include "Joueur.h"

class Partie {
private:
    vector<Joueur*> tab_joueurs;
    unsigned int joueur_actuel;
    unsigned int nb_monuments_win;
public:
    void jouer_partie();
    void jouer_tour(Joueur* joueur_actuel);
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    Partie(vector<Joueur*> liste_joueurs, vector<EditionDeJeu*> editions);
    ~Partie() = default;
};

#endif //MACHI_KORO_PARTIE_H
