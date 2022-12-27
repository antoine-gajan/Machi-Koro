#include <iostream>
#include <string>
using namespace std;
#include "VuePartie.h"
#include "Partie.h"

VuePartie::VuePartie(QWidget *parent){
    /// Constructeur de VuePartie
    // Attributs principaux
    Partie *partie_actuelle = Partie::get_instance();
    parent_fenetre = parent;
    fenetre_carte = nullptr;

    structure = new QVBoxLayout();


    //Création de l'entete de la page (pourquoi pas créer une classe VueEntete?)

    /// ****************************************************************************************************************
    /// ************************************ Création de l'entete de la page *******************************************
    /// ****************************************************************************************************************

    entete = new QHBoxLayout();

    //Affichage du nom de l'édition de jeu

    label_edj = new QLabel;
    // Permet de séparer les noms des éditions et extensions de jeu par un espace
    string nom_edj;
    for (auto it : partie_actuelle->get_nom_edition()){
        if (it != partie_actuelle->get_nom_edition().back()){
            nom_edj += it + " + ";
        }
        else{
            nom_edj += it;
        }
    }
    label_edj->setText("Profil de la partie : " + QString::fromStdString(nom_edj));
    label_edj->setFixedSize(300, 50);
    label_edj->setAlignment(Qt::AlignLeft);

    entete->addWidget(label_edj);

    //Affichage du nom du joueur actuel
    label_joueur_actuel = new QLabel;
    string nom_joueur = "Joueur actuel : \"" + partie_actuelle->get_tab_joueurs()[partie_actuelle->get_joueur_actuel()]->get_nom() + "\"";
    label_joueur_actuel->setText(QString::fromStdString(nom_joueur));
    label_joueur_actuel->setFixedSize(300, 50);
    label_joueur_actuel->setAlignment(Qt::AlignCenter);
    entete->addWidget(label_joueur_actuel);
    structure->addLayout(entete, 10);

    /// ****************************************************************************************************************
    /// ************************************              FIN                *******************************************
    /// ************************************ Création de l'entete de la page *******************************************
    /// ****************************************************************************************************************

    //Affichage de la valeur des dés

    display_des = new QVBoxLayout;

    label_de1 = new QLabel;
    label_de1->setText(QString::number(partie_actuelle->get_de_1()));
    display_des->addWidget(label_de1);

    label_de2 = new QLabel;
    label_de1->setText(QString::number(partie_actuelle->get_de_2()));
    display_des->addWidget(label_de2);

    entete->addLayout(display_des);

    /// ****************************************************************************************************************
    /// ************************************ Création du SHOP et de la PIOCHE ******************************************
    /// ****************************************************************************************************************

    ///Affichage du Shop et de la Pioche

    body = new QHBoxLayout;

    view_pioche = new VuePioche(*(partie_actuelle->get_pioche()), nullptr);

    view_shop = new VueShop(*(partie_actuelle->get_shop()), nullptr);

    body->addLayout(view_pioche,1);
    body->addLayout(view_shop,100);

    structure->addLayout(body,50);

    // Boutons de navigation gauche et droite dans les Vues Joueurs
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));

    layout = new QHBoxLayout();

    layout->addWidget(b1);

    nb_joueurs = partie_actuelle->get_tab_joueurs().size();
    joueur_affiche = 0;
    vue_joueur = new VueJoueur(Partie::get_instance()->get_tab_joueurs()[joueur_affiche], true, parent);
    layout->addWidget(vue_joueur);

    layout->addWidget(b2);

    structure->addLayout(layout,40);
    setLayout(structure);
    this->setWindowState(Qt::WindowFullScreen);
}


void VuePartie::d_click(){
    Partie *partie_actuelle = Partie::get_instance();
    /// Slot bouton droit
    joueur_affiche = (joueur_affiche + 1) % nb_joueurs;
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(partie_actuelle->get_joueur_actuel() == joueur_affiche){
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],true, parent_fenetre);
    }
    else{
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],false,  parent_fenetre);
    }

    // Remplacement par la nouvelle
    layout->replaceWidget(old, vue_joueur);
    delete old;
    // Mise à jour de l'affichage
    update();
}


void VuePartie::g_click(){
    Partie *partie_actuelle = Partie::get_instance();
    /// Slot bouton gauche
    joueur_affiche = (joueur_affiche - 1) % nb_joueurs;
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(partie_actuelle->get_joueur_actuel() == joueur_affiche){
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],true, parent_fenetre);
    }
    else{
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],false,  parent_fenetre);
    }
    // Remplacement par la nouvelle
    layout->replaceWidget(old, vue_joueur);
    delete old;
    // Mise à jour de l'affichage
    update();
}

void VuePartie::update_vue_joueur() {
    Partie *partie_actuelle = Partie::get_instance();
    /// Fonction pour mettre à jour la vue joueur actuelle
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(partie_actuelle->get_joueur_actuel() == joueur_affiche){
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],true, parent_fenetre);
    }
    else{
        vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche],false,  parent_fenetre);
    }
    // Remplacement par la nouvelle
    layout->replaceWidget(old, vue_joueur);
    delete old;
    // Mise à jour de l'affichage
    update();
}


