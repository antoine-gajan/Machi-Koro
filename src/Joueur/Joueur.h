#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H

#include <iostream>
#include <map>
#include "../cartes/monument/Monument.h"
#include "../cartes/batiment/Batiment.h"

using namespace std;

enum strat_IA {aleatoire, agressive, defensif, neutre};
// Agressive : veut construire des batiments de couleur rouge
// Defensif : veut construire des batiments de couleur bleu
// Neutre : veut construire des batiments
// Aleatoire : va construire ou pas un batiment au hasard

class Joueur {
    private:
        string nom;
        map<Monument*, bool> liste_monument;
        map<Batiment*, unsigned int> liste_batiment;
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

        map<Monument*, bool> get_liste_monument() const {return liste_monument;};
        map<Batiment*, unsigned int> get_liste_batiment() const {return liste_batiment;};

        /***** Setters *****/
        void set_argent(unsigned int arg) {argent = arg;};

        void activer_monument(Monument *mon);
        void ajouter_batiment(Batiment *bat);

};

#endif //MACHI_KORO_JOUEUR_H
