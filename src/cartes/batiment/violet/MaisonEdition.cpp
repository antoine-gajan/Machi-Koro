#include "MaisonEdition.h"
#include "Partie.h"
#include "Joueur.h"

MaisonEdition::MaisonEdition():
        Batiment("MaisonEdition",
                 5,
                 "Recevez 1 piece de chaque joueur pour chaque etablissement de type restaurant et commerce qu'il possede.",
                 "../../../assets/batiments/Violet/Maison-d-edition.jpg",
                 Violet,
                 list<unsigned int>{7},
                 "special") {
    ///Constructeur de Maison d'Edition
}



void MaisonEdition::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de la maison d'edition
    cout << "Activation de l'effet de la maison d'edition." << endl;

    // Variables utiles
    const vector<Joueur*> tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur* j_actuel = tab_joueurs[possesseur];
    unsigned int nb_bat, argent_joueur;

    // Parcours du tableau de joueurs
    for (Joueur* joueur : tab_joueurs){
        nb_bat = joueur->count_type("restaurant") + joueur->count_type("commerce");
        argent_joueur = joueur->get_argent();
        if (argent_joueur >= nb_bat){
            // On ne prend que l'argent nécessaire
            joueur->set_argent(argent_joueur - nb_bat);
            j_actuel->set_argent(j_actuel->get_argent() + nb_bat);
            // Affichage de la transaction
            cout << "Le joueur " << joueur->get_nom() << " donne " << nb_bat << " à " << j_actuel->get_nom() <<endl;
            cout << "Le joueur " << joueur->get_nom() << " a maintenant " << joueur->get_argent() <<endl;
            cout << "Le joueur " << j_actuel->get_nom() << " a maintenant " << j_actuel->get_argent() <<endl;
        }
        else{
            // On vide le compte du joueur
            joueur->set_argent(0);
            j_actuel->set_argent(j_actuel->get_argent() + argent_joueur);
            // Affichage de la transaction
            cout << "Le joueur " << joueur->get_nom() << " donne " << argent_joueur << " à " << j_actuel->get_nom() <<endl;
            cout << "Le joueur " << joueur->get_nom() << " a maintenant " << joueur->get_argent() <<endl;
            cout << "Le joueur " << j_actuel->get_nom() << " a maintenant " << j_actuel->get_argent() <<endl;
        }
    }
}



