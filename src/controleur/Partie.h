#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <list>
#include "EditionDeJeu/EditionDeJeu.h"
#include "Joueur.h"
#include "Shop.h"
#include "Pioche.h"
#include <vector>
#include "../cartes/batiment/Batiment.h"
#include <string>

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


    class Singleton {
    public :
        Partie* instance = nullptr;
        ~Singleton() {delete instance; instance = nullptr;};
    };
    static Singleton singleton;

public:


    explicit Partie(EditionDeJeu* edition, const vector<EditionDeJeu *>& extensions = vector<EditionDeJeu *>());
    ~Partie() = default;
    //********** Jouer une partie **********//
    void jouer_partie();
    void jouer_tour();
    bool est_gagnant(Joueur *joueur) const;
    unsigned int get_de_2() const {return de_2;}
    void set_de_2(unsigned int de2) {Partie::de_2 = de2;}

    //********** Constructeurs et getters **********//
    unsigned int get_joueur_actuel() const {return joueur_actuel;};
    Singleton& get_instance();

    //********** Methodes **********//
    //********** Methodes statiques **********//
    static vector<Batiment*> map_to_vector(const map<Batiment*, unsigned int>& map_batiments);
    // Compte le nombre de cartes d'un type donne dans le jeu d'un Joueur
    static unsigned int count_type(Joueur *joueur, const string& type);

    // Renvoie l'indice d'un joueur entier valide different de l'indice du joueur actuel
    static unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);

    // selection d'un batiment chez un joueur, on fait choisir parmis la liste des batiments possedes par le joueur
    // on renvoit un simple pointeur sur le batiment (qui lui n'est pas specifique au joueur)
    static Batiment* selectionner_batiment(Joueur *joueur);
    //renvoie un pointeur sur le batiment si le joueur possede le batiment, cette fois-ci, le nom du batiment est passe en parametre, utile pour certains effets
    static Batiment* possede_batiment(Joueur *joueur,const string& nom_bat);


    // idem mais pour monument
    static Monument* selectionner_monument(Joueur *joueur);
    static Monument* possede_monument(Joueur *joueur, const string& nom_mon);

    // Fonction qui retourne une liste des batiments non violets possede par un joueur
    static map<Batiment*, unsigned int> get_liste_bat_non_special(Joueur* j);

    //Fonction qui echange le batiment 1 du joueur 1 avec le batiment 2 du joueur 2
    static void swap_bat_players(Joueur *j1, Joueur *j2, Batiment *bat1, Batiment *bat2);

    static void don_argent(Joueur* j1, unsigned int argent, Joueur* j2);

    //********** Methodes non statiques **********//
    void ajout_batiment(Batiment *batiment);

    void acheter_carte();
    void acheter_monu();//sous fonction appelee dans acheter_carte
    void acheter_bat();//sous fonction appelee dans acheter_carte
    bool echanger_argent(unsigned int indice_joueur1, unsigned int indice_joueur2, unsigned int somme);
    void rejouer_tour();

    vector<Batiment *> get_starter();
};

#endif //MACHI_KORO_PARTIE_H
