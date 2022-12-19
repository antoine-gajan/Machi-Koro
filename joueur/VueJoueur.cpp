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
    QVBoxLayout* layout_informations_gauche = new QVBoxLayout;
    QHBoxLayout* layout_haut_gauche = new QHBoxLayout;

    // Création de la grid
    layout_batiments = new QGridLayout;
    layout_monuments = new QGridLayout;
    int i = 0;
    int ind_cartes;
    int ind_couleurs = 0;
    // Création des vues des batiments du joueur
    for (auto& couleur : joueur->get_liste_batiment()){
        ind_cartes = 0;
        for (auto bat : couleur.second){
            // Affichage du batiment
            vue_batiments.push_back(new VueCarte(*bat.first, parent));
            layout_batiments->addWidget(vue_batiments[i], ind_couleurs, ind_cartes);
            ind_cartes++;
            i++;
        }
        ind_couleurs++;
    }

    // Création des vues des monuments du joueur
    for (auto& mon : joueur->get_liste_monument()){
        vue_monuments.push_back(new VueCarte(*mon.first, parent));
        layout_monuments->addWidget(vue_monuments[ind_cartes], ind_cartes/3, ind_cartes%3);
        ind_cartes++;
    }

    // Création du layout gauche
    layout_haut_gauche->addWidget(nom_joueur);
    layout_haut_gauche->addWidget(argent);
    layout_informations_gauche->addLayout(layout_haut_gauche);

    // Ajout des layouts à la page d'informations
    layout_informations->addLayout(layout_informations_gauche);
    layout_informations->addLayout(layout_batiments);

    setLayout(layout_informations);
}
