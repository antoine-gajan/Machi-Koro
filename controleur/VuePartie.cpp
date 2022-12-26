#include <iostream>
#include <string>
using namespace std;
#include "VuePartie.h"
#include "Partie.h"

VuePartie::VuePartie(Partie *partie, QWidget *parent){
    /// Constructeur de VuePartie
    // Attributs principaux
    partie_actuelle = partie;
    parent_fenetre = parent;

    structure = new QVBoxLayout();

    //Création de l'entete de la page (pourquoi pas créer une classe VueEntete?)

    entete = new QHBoxLayout();

    //Affichage du nom de l'édition de jeu

    label_edj = new QLabel;
    string nom_edj;
    for (auto it : partie->get_nom_edition()){
        nom_edj += it + " ";
    }
    label_edj->setText("Profil de la partie : " + QString::fromStdString(nom_edj));

    entete->addWidget(label_edj);

    //Affichage du nom du joueur actuel
    label_joueur_actuel = new QLabel;
    string nom_joueur = "Joueur actuel : ";
    nom_joueur += partie->get_tab_joueurs()[partie->get_joueur_actuel()]->get_nom();
    label_joueur_actuel->setText(QString::fromStdString(nom_joueur));
    entete->addWidget(label_joueur_actuel);

    structure->addLayout(entete,10);

    //Affichage de la valeur des dés

    display_des = new QVBoxLayout;

    label_de1 = new QLabel;
    label_de1->setText(QString::number(partie->get_de_1()));
    display_des->addWidget(label_de1);

    label_de2 = new QLabel;
    label_de1->setText(QString::number(partie->get_de_2()));
    display_des->addWidget(label_de2);

    entete->addLayout(display_des);

    ///Affichage du Shop et de la Pioche (va falloir créer deux classes vue shop et vue pioche certainement)

    body = new QHBoxLayout;

    view_pioche = new VuePioche(*(partie->get_pioche()), nullptr);
    /*
    VueCarte* view_pioche = new VueCarte(*b,true);
    body->addWidget(view_pioche);
*/

    view_shop = new VueShop(*(partie->get_shop()), nullptr);

    body->addLayout(view_pioche,1);
    body->addLayout(view_shop,100);

    structure->addLayout(body,50);
    /*auto *menu = new QWidget();
    auto *jeu = new QWidget();

    resize_and_center(menu , 700, 500);
    build_content_menu(menu);
    menu->show();


    resize_and_center(jeu, 1000, 700);
    build_content_jeu(jeu);
    jeu->show();


    return QApplication::exec();*/

    // Boutons de navigation gauche et droite dans les Vues Joueurs
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));

    layout = new QHBoxLayout();

    layout->addWidget(b1);

    nb_joueurs = partie->get_tab_joueurs().size();
    joueur_affiche = 0;
    vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche], true, parent);
    layout->addWidget(vue_joueur);

    layout->addWidget(b2);

    structure->addLayout(layout,40);
    setLayout(structure);
    this->setWindowState(Qt::WindowFullScreen);
}


void VuePartie::d_click(){
    /// Slot bouton droit
    joueur_affiche = (joueur_affiche + 1) % nb_joueurs;
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(get_partie_actuelle()->get_joueur_actuel() == joueur_affiche){
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
    /// Slot bouton gauche
    joueur_affiche = (joueur_affiche - 1) % nb_joueurs;
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(get_partie_actuelle()->get_joueur_actuel() == joueur_affiche){
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
    /// Fonction pour mettre à jour la vue joueur actuelle
    // Récupération de l'ancienne vue
    VueJoueur *old = vue_joueur;
    // Création de la nouvelle
    if(get_partie_actuelle()->get_joueur_actuel() == joueur_affiche){
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


