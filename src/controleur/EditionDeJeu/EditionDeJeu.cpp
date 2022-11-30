#include "EditionDeJeu.h"

EditionDeJeu::EditionDeJeu(std::string& nom, unsigned int joueurs_min, unsigned int joueurs_max, unsigned int mon_win,
                           Monument* list_mon[], unsigned int quantite_mon[], Batiment* list_bat[], unsigned int quantite_bat[], bool edition) :
                           nom(nom),
                           nb_joueurs_min(joueurs_min),
                           nb_joueurs_max(joueurs_max),
                           nb_monuments_win(mon_win),
                           est_edition(edition) {
    /// Constructeur de EditionDeJeu

    //Gestion des erreurs
    if (nom.empty()){
        throw invalid_argument("Le nom de l'édition ne peut être vide.");
    }

    if (joueurs_min > joueurs_max){
        throw invalid_argument("Le nombre de joueurs minimal doit être inférieur au nombre de joueurs maximal.");
    }

    // Ajout des batiments initiaux
    while (list_bat != nullptr && quantite_bat != nullptr) {
        batiments.insert(pair<Batiment*, unsigned int>(*list_bat, *quantite_bat));
        list_bat++;
        quantite_bat++;
    }

    // Si les deux listes ne sont pas vides, c'est qu'elles n'étaient pas de même taille donc erreur
    if (list_bat || quantite_bat) throw invalid_argument("Les tableaux contenant les batiments et la quantité des batiments ne sont pas de même taille.");

    // Ajout des monuments initiaux

    while (list_mon != nullptr) {
        monuments.insert(pair<Monument*, unsigned int>(*list_mon, *quantite_mon));
        list_mon++;
        quantite_mon++;
    }

    // Si les deux listes ne sont pas vides, c'est qu'elles n'étaient pas de même taille donc erreur
    if (list_mon || quantite_mon) throw invalid_argument("Les tableaux contenant les monuments et leurs quantités ne sont pas de même taille.");

}
