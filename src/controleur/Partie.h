#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <list>
#include "EditionDeJeu/EditionDeJeu.h"
#include "Joueur.h"
#include "Shop.h"
#include "Pioche.h"

class Partie {
private:
    map<Batiment*, unsigned int> list_batiments;

    vector<Monument*> list_monuments;
    vector<Joueur*> tab_joueurs;
    vector<EditionDeJeu*> editions;

    unsigned int joueur_actuel;
    unsigned int nb_monuments_win;
    Shop* shop;
    Pioche* pioche;


    class Singleton {
    public :
        Partie* instance = nullptr;
        ~Singleton() {delete instance; instance = nullptr;};
    };
    static Singleton singleton;

    Partie();
    ~Partie() = default;


public:
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour();
    bool est_gagnant(Joueur *joueur);

    //********** Constructeurs et getters **********//
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    Singleton& get_instance();

};

#endif //MACHI_KORO_PARTIE_H
