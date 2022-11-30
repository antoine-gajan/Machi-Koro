#include "EditionDeJeu.h"

EditionDeJeu::EditionDeJeu(const string& nom, unsigned int joueurs_min, unsigned int joueurs_max, unsigned int mon_win, vector<Monument*> monuments, map<Batiment*, unsigned int> batiments, bool edition):
                           nom(nom),
                           nb_joueurs_min(joueurs_min),
                           nb_joueurs_max(joueurs_max),
                           nb_monuments_win(mon_win),
                           batiments(batiments),
                           monuments(monuments),
                           est_edition(edition) {
    /// Constructeur de EditionDeJeu

    //Gestion des erreurs
    if (nom.empty()){
        throw invalid_argument("Le nom de l'édition ne peut être vide.");
    }

    if (nb_joueurs_min > nb_joueurs_max){
        throw invalid_argument("Le nombre de joueurs minimal doit être inférieur au nombre de joueurs maximal.");
    }

}
