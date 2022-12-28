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
    entete_gauche = new QVBoxLayout();

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
    // Profil de la partie
    label_edj->setText("Profil de la partie : " + QString::fromStdString(nom_edj));
    label_edj->setFixedSize(300, 50);
    label_edj->setAlignment(Qt::AlignCenter);

    entete_gauche->addWidget(label_edj);

    //Affichage du nom du joueur actuel
    label_joueur_actuel = new QLabel;
    string nom_joueur = "Joueur actuel : \"" + partie_actuelle->get_tab_joueurs()[partie_actuelle->get_joueur_actuel()]->get_nom() + "\"";
    label_joueur_actuel->setText(QString::fromStdString(nom_joueur));
    label_joueur_actuel->setFixedSize(300, 50);
    label_joueur_actuel->setAlignment(Qt::AlignCenter);
    entete_gauche->addWidget(label_joueur_actuel);
    entete->addLayout(entete_gauche);
    structure->addLayout(entete, 10);

    //Ajout de l'image dans l'entete
    image_entete = new QLabel;
    QPixmap* image = new QPixmap("../assets/annexes/Machi-Koro.png");
    image->scaled(300,50, Qt::KeepAspectRatio);
    image_entete->setPixmap(*image);

    entete->addWidget(image_entete);

    //Affichage de l'image "Machi Koro"

    /// ****************************************************************************************************************
    /// ************************************              FIN                *******************************************
    /// ************************************ Création de l'entete de la page *******************************************
    /// ****************************************************************************************************************

    //Affichage de la valeur des dés

    display_des = new QVBoxLayout;
    layout_de_1 = new QHBoxLayout;
    layout_de_2 = new QHBoxLayout;

    bouton_lancer_de_1 = new QPushButton("Lancer le dé 1");
    bouton_lancer_de_2 = new QPushButton("Lancer le dé 2");
    bouton_lancer_de_1->setFixedSize(150, 50);
    bouton_lancer_de_2->setFixedSize(150, 50);
    bouton_lancer_de_1->setEnabled(false);
    bouton_lancer_de_2->setEnabled(false);
    layout_de_1->addWidget(bouton_lancer_de_1);
    layout_de_2->addWidget(bouton_lancer_de_2);

    label_de1 = new QLabel;
    label_de1->setText(QString::number(partie_actuelle->get_de_1()));
    label_de1->setAlignment(Qt::AlignHCenter);
    layout_de_1->addWidget(label_de1);
    layout_de_1->setAlignment(Qt::AlignCenter);

    label_de2 = new QLabel("Valeur de dé 2");
    label_de2->setText(QString::number(partie_actuelle->get_de_2()));
    label_de1->setAlignment(Qt::AlignHCenter);
    layout_de_2->addWidget(label_de2);
    layout_de_2->setAlignment(Qt::AlignCenter);

    display_des->addLayout(layout_de_1);
    display_des->addLayout(layout_de_2);

    entete->addLayout(display_des);

    /// ****************************************************************************************************************
    /// **************************************** MILIEU DE L'AFFICHAGE *************************************************
    /// ****************************************************************************************************************

    ///Affichage du Shop, de la Pioche et des informations

    body = new QHBoxLayout;
    // Pioche
    view_pioche = new VuePioche(partie_actuelle->get_pioche(), nullptr);
    fenetre_pioche = new QWidget;
    fenetre_pioche->setFixedSize(300, 520);
    fenetre_pioche->setLayout(view_pioche);
    body->addWidget(fenetre_pioche, 100, Qt::AlignCenter);

    // Shop
    scroll_shop = new QScrollArea;
    widget_shop = new QWidget;
    view_shop = new VueShop(*(partie_actuelle->get_shop()), nullptr);
    widget_shop->setLayout(view_shop);
    scroll_shop->setWidget(widget_shop);
    scroll_shop->setWidgetResizable(true);
    unsigned int largeur = floor(sqrt(partie_actuelle->get_shop()->get_nb_tas_reel()));
    scroll_shop->setFixedWidth(130 * largeur);
    scroll_shop->setFixedHeight(520);
    scroll_shop->setStyle(QStyleFactory::create("Fusion"));
    body->addWidget(scroll_shop,100, Qt::AlignCenter);

    // Informations sur le tour
    infos = new VueInfo(nullptr);
    widget_infos = new QWidget;
    widget_infos->setLayout(infos);
    widget_infos->setFixedSize(300, 520);
    body->addWidget(widget_infos, 100, Qt::AlignCenter);


    structure->addLayout(body,50);


    // Boutons de navigation gauche et droite dans les Vues Joueurs
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));

    // Partie basse avec la vue joueur
    layout = new QHBoxLayout();

    layout->addWidget(b1);

    nb_joueurs = partie_actuelle->get_tab_joueurs().size();
    joueur_affiche = 0;
    vue_joueur = new VueJoueur(Partie::get_instance()->get_tab_joueurs()[joueur_affiche], true, parent);
    layout->addWidget(vue_joueur);

    layout->addWidget(b2);

    structure->addLayout(layout,40);
    setLayout(structure);
    this->setWindowState(Qt::WindowMaximized);
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

void VuePartie::lancer_de_1_display(){
    Partie* partie_actuelle = Partie::get_instance();
    /// Fonction pour mettre à jour le dé 1 de manière graphique

    bouton_lancer_de_1->setEnabled(true);
    // On vient connecter le bouton du dé 1 avec un slot personnalisé
    QObject::connect(bouton_lancer_de_1, SIGNAL(clicked()), this, SLOT(clicked_event_de_1()));

}

void VuePartie::lancer_de_2_display(){
    /// Fonction pour mettre à jour le dé 2 de manière graphique
    Partie* partie_actuelle = Partie::get_instance();
    bouton_lancer_de_2->setEnabled(true);
    // On vient connecter le bouton du dé 2 avec un slot personnalisé
    QObject::connect(bouton_lancer_de_1, SIGNAL(clicked()), this, SLOT(clicked_event_de_2()));

}

void VuePartie::clicked_event_de_1() {
    // Slot personnalisé qui vient créer une nouvelle valeur pour le dé et l'injecte dans partie
    Partie* partie_actuelle = Partie::get_instance();
    partie_actuelle->set_de_1(partie_actuelle->lancer_de());
    bouton_lancer_de_1->setEnabled(false);
    // On appelle la fonction de mise à jour de l'affichage des dés
    update_des();
}

void VuePartie::clicked_event_de_2() {
    // Slot personnalisé qui vient créer une nouvelle valeur pour le dé et l'injecte dans partie
    Partie* partie_actuelle = Partie::get_instance();
    partie_actuelle->set_de_2(partie_actuelle->lancer_de());
    bouton_lancer_de_2->setEnabled(false);
    // On appelle la fonction de mise à jour de l'affichage des dés
    update_des();
}

void VuePartie::update_des() {
    // Mise à jour de l'affichage des dés
    Partie* partie_actuelle = Partie::get_instance();
    label_de1->setText(QString::fromStdString(std::to_string(partie_actuelle->get_de_1())));
    label_de2->setText(QString::fromStdString(std::to_string(partie_actuelle->get_de_2())));
}

void VuePartie::update_nom_joueur(){
    // Mise à jour du nom du joueur actuel dans l'entete
    Partie* partie_actuelle = Partie::get_instance();
    label_joueur_actuel->setText(QString::fromStdString(partie_actuelle->get_tab_joueurs()[joueur_affiche]->get_nom()));
}