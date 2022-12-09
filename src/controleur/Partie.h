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

public:


    Partie(EditionDeJeu* edition, vector<EditionDeJeu *> extensions = vector<EditionDeJeu *>());
    ~Partie() = default;
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour();
    bool est_gagnant(Joueur *joueur);

    //********** Constructeurs et getters **********//
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    Singleton& get_instance();

    //********** Methodes **********//
    vector<Batiment*> map_to_vector(map<Batiment*, unsigned int> map_batiments);
    void ajout_batiment(Batiment *batiment);

    void acheter_carte(Joueur* joueur_actuel);
    void acheter_monu(Joueur* joueur_actuel);//sous fonction appelee dans acheter_carte
    void acheter_bat(Joueur* joueur_actuel);//sous fonction appelee dans acheter_carte
    void echanger_argent(Joueur* joueur1,Joueur* joueur2);

    vector<Batiment *> get_starter();
};

#endif //MACHI_KORO_PARTIE_H
