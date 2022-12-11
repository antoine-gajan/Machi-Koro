#ifndef MACHI_KORO_PARTIE_H
#define MACHI_KORO_PARTIE_H

#include <list>
#include <vector>
#include <string>

#include "EditionDeJeu.h"
#include "Shop.h"
#include "Pioche.h"
#include "Joueur.h"

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
        static Partie* instance;


        /*class Singleton {
        public :
            Partie* instance = nullptr;
            ~Singleton() {delete instance; instance = nullptr;};
        };
        static Singleton singleton;
        */
    public:
        //// Constructeur et Destructeur ////
        ~Partie();

        ////********** A VERIFIER **********////
    explicit Partie(EditionDeJeu* edition, const vector<EditionDeJeu *>& extensions = vector<EditionDeJeu *>());

        //********** Jouer une partie **********//
        void jouer_partie();
        void jouer_tour();
        bool est_gagnant(unsigned int j) const;
        unsigned int get_de_2() const {return de_2;}
        void set_de_2(unsigned int de2) {Partie::de_2 = de2;}

        //********** Constructeurs et getters **********//
        unsigned int get_joueur_actuel() const {return joueur_actuel;};
        static Partie& get_instance();
        void liberer_instance();
        const vector <Joueur*>& get_tab_joueurs() const {return tab_joueurs;};

        //********** Methodes **********//
        //********** Methodes statiques **********//
        static vector<Batiment*> map_to_vector(const map<Batiment*, unsigned int>& map_batiments);

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
