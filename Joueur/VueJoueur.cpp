#include "VueJoueur.h"

VueJoueur::VueJoueur(Joueur* joueur, QWidget *parent) {
    /// Vue d'un joueur
    // Argent du joueur
    argent=new QLCDNumber;
    argent->display((int)joueur->get_argent());
    argent->setFixedHeight(30);

    // Barre avec les informations du joueur
    layoutInformations=new QHBoxLayout;
    layoutBatiments=new QGridLayout;

    // Création des vue des cartes du joueur
    for (auto& couleur : joueur->get_liste_batiment()){
        for (auto bat : couleur.second){
            // Affichage de la carte (à faire)
        }
    }


}
