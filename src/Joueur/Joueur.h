#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H

#include <map>
#include <vector>
#include "Monument.h"
#include "Batiment.h"

enum strat_IA {aleatoire, agressive, defensif, none};
// Agressive : veut construire des batiments de couleur rouge
// Defensif : veut construire des batiments de couleur bleu
// Aleatoire : va construire ou pas un batiment au hasard
// None : n'est pas une IA

class Joueur {
    private:
    /*** Attributs de la classe ***/

        string nom;
        map<Monument*, bool> liste_monument;
        map<couleur_bat, map<Batiment*, unsigned int>> liste_batiment;
        unsigned int argent;
        bool est_ia;
        strat_IA strategie;

    public:
        /*** Constructeurs et destructeur ***/
        Joueur(const string& nom, const vector<Monument *>&list_mon, const vector<Batiment *>&list_bat, unsigned int arg_depart, strat_IA stratIa=none);
        ~Joueur();

        /***** Getters *****/
        unsigned int get_argent() const {return argent;};
        const string& get_nom() const {return nom;};
        bool get_est_ia() const {return est_ia;};
        strat_IA get_strategie() const {return strategie;};
        const map<Monument*, bool>& get_liste_monument() const {return liste_monument;};
        map<couleur_bat, map<Batiment*, unsigned int>> get_liste_batiment() const {return liste_batiment;};
        map<Batiment*, unsigned int> get_liste_batiment(couleur_bat couleur) {return liste_batiment[couleur];};
        vector<unsigned int> get_repartition_argent() const;
        vector<Monument*> get_monument_jouables() const;
        const map<Batiment*, unsigned int>& get_liste_bat_non_special();

        /***** Setters *****/
        void set_argent(unsigned int arg) {argent = arg;};
        void set_liste_batiment(map<couleur_bat, map<Batiment*, unsigned int>>& liste_bat);

        /***** Autres methodes *****/
        void activer_monument(Monument *mon);
        void desactiver_monument(Monument *mon);
        void ajouter_batiment(Batiment *bat);
        void retirer_batiment(Batiment *bat);
        void afficher_cartes() const;
        void afficher_joueur() const;
        // Compte le nombre de cartes d'un type donne dans le jeu d'un Joueur
        unsigned int count_type(const string& type) const;
};

#endif //MACHI_KORO_JOUEUR_H
