#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H

#include <map>
#include <vector>
#include "Monument.h"
#include "Batiment.h"

enum strat_IA {aleatoire, agressive, defensif, neutre};
// Agressive : veut construire des batiments de couleur rouge
// Defensif : veut construire des batiments de couleur bleu
// Neutre : veut construire des batiments
// Aleatoire : va construire ou pas un batiment au hasard

class Joueur {
    private:
    /*** Attributs de la classe ***/

    string nom;
        map<Monument*, bool> liste_monument;
        map<string, map<Batiment*, unsigned int>> liste_batiment;
        unsigned int argent;
        bool est_ia;
        strat_IA strategie;

    public:
        /*** Constructeurs et destructeur ***/
        Joueur(string nom, Monument *list_mon[], Batiment *list_bat[], unsigned int arg_depart);
        Joueur(string nom, Monument *list_mon[], Batiment *list_bat[], unsigned int arg_depart, strat_IA stratIa);
        ~Joueur();

        /***** Getters *****/
        unsigned int get_argent() const {return argent;};
        string get_nom() const {return nom;};
        bool get_est_ia() const {return est_ia;};
        strat_IA get_strategie() const {return strategie;};
        unsigned int * get_repartition_argent() const;

        const map<Monument*, bool>& get_liste_monument() const {return liste_monument;};
        const map<string, map<Batiment*, unsigned int>>& get_liste_batiment() const {return liste_batiment;};
        map<string, map<Batiment*, unsigned int>>& get_liste_batiment() {return liste_batiment;};
        vector<Monument*> get_monument_jouables() const;

        /***** Setters *****/
        void set_argent(unsigned int arg) {argent = arg;};

        /***** Autres méthodes *****/
        void activer_monument(Monument *mon);
        void desactiver_monument(Monument *mon);
        void ajouter_batiment(Batiment *bat);
        void retirer_batiment(Batiment *bat);

        void acheter_carte(Carte *carte);
};

#endif //MACHI_KORO_JOUEUR_H
