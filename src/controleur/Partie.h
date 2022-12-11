#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <list>
#include <vector>
#include <string>
#include <algorithm>

#include "EditionDeJeu.h"
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
    unsigned int de_1;
    unsigned int de_2;

    Shop* shop;
    Pioche* pioche;

    static Partie* singleton;

    //// Constructeur et Destructeur ////
    ~Partie();
    explicit Partie(EditionDeJeu* edition, const vector<EditionDeJeu *>& extensions = vector<EditionDeJeu *>());

public:
    Partie(Partie const&) = delete;
    void operator=(const Partie&) = delete;
    static Partie* get_instance();
    static void liberer_instance();


    ////********** A VERIFIER **********////
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour();
    bool est_gagnant(unsigned int j) const;
    unsigned int get_de_2() const {return de_2;}

    void set_de_2(unsigned int de2) {de_2 = de2;}
    //********** Constructeurs et getters **********//
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    const vector <Joueur*>& get_tab_joueurs() const {return tab_joueurs;};

    //********** Methodes **********//
    //********** Methodes statiques **********//
    static vector<Batiment*> map_to_vector(const map<Batiment*, unsigned int>& map_batiments);
    // Compte le nombre de cartes d'un type donne dans le jeu d'un Joueur
    static unsigned int count_type(Joueur *joueur, const string& type);

    // Renvoie l'indice d'un joueur entier valide different de l'indice du joueur actuel
    static unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);

    static void don_argent(Joueur* j1, unsigned int argent, Joueur* j2);

    //********** Methodes non statiques **********//
    void ajout_batiment(Batiment *batiment);

    bool acheter_carte();
    bool acheter_monu();//sous fonction appelee dans acheter_carte
    bool acheter_bat();//sous fonction appelee dans acheter_carte
    bool transfert_argent(unsigned int indice_joueur1, unsigned int indice_joueur2, unsigned int somme);
    void rejouer_tour();

    vector<Batiment *> get_starter();
};

#endif //MACHI_KORO_PARTIE_H
