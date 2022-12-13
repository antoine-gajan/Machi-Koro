#include "Arboretum.h"
#include "Partie.h"
#include "Joueur.h"

Arboretum::Arboretum():
        Batiment("Arboretum",
                 3,
                 "Rassemblez les pieces de tous les joueurs puis redistribuez les de maniere egale entre tous. La banque completera s'il manque des pieces pour une redistribution egale.",
                 "../../../assets/batiments/Violet/Arboretum.jpg",
                 Violet,
                 list<unsigned int>{11, 12, 13},
                 "special") {
    ///Constructeur de l'Arboretum
}



void Arboretum::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de l'arboretum
    cout << "Activation de l'effet de l'arboretum." << endl;
    int somme_totale = 0;
    vector<Joueur*> tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    // Calcul de l'argent total
    for (auto joueur : tab_joueurs){
        somme_totale += joueur->get_argent();
    }
    // Argent à répartir
    int montant_par_joueur = std::ceil(somme_totale/tab_joueurs.size());
    // Répartition
    for (auto joueur : tab_joueurs){
        joueur->set_argent(montant_par_joueur);
    }
}