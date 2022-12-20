#include "VueJoueur.h"
#include <QPixmap>

VueJoueur::VueJoueur(Joueur* joueur, QWidget *parent) {
    /// Vue d'un joueur
    // Nom du joueur
    j = joueur;
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
            vue_batiments.push_back(new VueCarte(*bat.first, true, parent));
            layout_batiments->addWidget(vue_batiments[i], ind_couleurs, ind_cartes);
            connect(vue_batiments[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
            ind_cartes++;
            i++;
        }
        ind_couleurs++;
    }
    QPushButton *bat_ferme = new QPushButton("Batiment Fermes");
    layout_batiments->addWidget(bat_ferme);
    connect(bat_ferme, SIGNAL(clicked()),this, SLOT(affichage_bat_ferme()));



    // Création des vues des monuments du joueur
    int ind_mon=0;
    for (auto& mon : joueur->get_liste_monument()){
        vue_monuments.push_back(new VueCarte(*mon.first,true, parent));
        layout_monuments->addWidget(vue_monuments[ind_mon], ind_mon/3, ind_mon%3);
        connect(vue_monuments[ind_mon],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
        ind_mon++;
    }

    // Création du layout gauche
    layout_haut_gauche->addWidget(nom_joueur);
    layout_haut_gauche->addWidget(argent);
    layout_informations_gauche->addLayout(layout_haut_gauche);
    layout_informations_gauche->addLayout(layout_monuments);

    // Ajout des layouts à la page d'informations
    layout_informations->addLayout(layout_informations_gauche);
    layout_informations->addLayout(layout_batiments);

    setLayout(layout_informations);
}

void VueJoueur::carteClique(VueCarte* vc){
    QWidget* fenetre2 = new QWidget();
    QLabel *label2 = new QLabel(fenetre2);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    label2->setPixmap(pixmap);
    label2->resize(pixmap.size());
    fenetre2->show();
}

void VueJoueur::affichage_bat_ferme(){
    int i = 0;
    QWidget* fenetre2 = new QWidget;
    layout_batiments_ferme = new QGridLayout(fenetre2);
    Joueur* joueur = get_joueur();
    QPixmap pixmap;
    QLabel *lab = new QLabel;
    for (auto bat : joueur->get_liste_batiment_fermes()){
        vue_batiments_ferme.push_back(new VueCarte(*bat, false, fenetre2));
        layout_batiments_ferme->addWidget(vue_batiments_ferme[i], i%4, i/4);
        i++;
    }


    setLayout(layout_batiments_ferme);

    fenetre2->show();
}
