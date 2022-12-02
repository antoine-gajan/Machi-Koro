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
    unsigned int joueur_actuel;
    unsigned int nb_monuments_win;
    Shop shop;
    Pioche pioche;
    vector<EditionDeJeu*> editions;
    class Singleton {
    public :
        Partie* instance = nullptr;
        ~Singleton() {delete instance; instance = nullptr;};
    };
    static Singleton singleton;
    Partie(vector<Joueur*> liste_joueurs, vector<EditionDeJeu*> editions);
    ~Partie() = default;


public:
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour(Joueur* joueur_actuel);
    bool est_gagnant(Joueur *joueur);

    //********** Constructeurs et getters **********//
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    Singleton& get_instance();

};

#endif //MACHI_KORO_PARTIE_H
