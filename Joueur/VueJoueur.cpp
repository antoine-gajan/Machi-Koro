#include "VueJoueur.h"

VueJoueur::VueJoueur(Joueur* joueur, QWidget *parent) {
    /// Vue d'un joueur
    // Nom du joueur
    nom_joueur = new QLabel;
    nom_joueur->setText(QString::fromStdString(joueur->get_nom()));
    // Argent du joueur
    argent=new QLCDNumber;
    argent->display((int)joueur->get_argent());
    argent->setFixedHeight(30);

    // Barre avec les informations du joueur
    layout_informations = new QHBoxLayout;
    layout_batiments = new QGridLayout;
    layout_monuments = new QGridLayout;

    int ind_cartes = 0;
    int ind_couleurs = 0;
    // Création des vues des batiments du joueur
    for (auto& couleur : joueur->get_liste_batiment()){
        for (auto bat : couleur.second){
            // Affichage du batiment
            vue_batiments.push_back(new VueCarte(*bat.first, parent));
            layout_batiments->addWidget(vue_batiments[ind_cartes], ind_couleurs, ind_cartes);
            ind_cartes++;
        }
        ind_cartes = 0;
        ind_couleurs++;
    }

    // Création des vues des monuments du joueur
    for (auto& mon : joueur->get_liste_monument()){
        vue_monuments.push_back(new VueCarte(*mon.first, parent));
        layout_monuments->addWidget(vue_monuments[ind_cartes], ind_cartes/3, ind_cartes%3);
        ind_cartes++;
    }

    // Ajout des layouts
    layout_informations->addLayout(layout_monuments);
    layout_informations->addLayout(layout_batiments);
}
