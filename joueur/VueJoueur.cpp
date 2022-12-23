#include "VueJoueur.h"
#include <QPixmap>

VueJoueur::VueJoueur(Joueur* j,bool e_j_a, QWidget *parent) {
    /// Vue d'un joueur
    est_joueur_actuel = e_j_a;
    joueur = j;
    // Nom du joueur
    nom_joueur = new QLabel;
    if(j->get_est_ia()){
        nom_joueur->setText(QString::fromStdString(joueur->get_nom()+" (IA)"));
    }
    else{
        nom_joueur->setText(QString::fromStdString(joueur->get_nom()));
    }
    // Argent du joueur
    argent=new QLCDNumber;
    argent->display((int)joueur->get_argent());
    argent->setFixedSize(70,30);
    //

    // Barre avec les informations du joueur
    layout_informations = new QHBoxLayout;
    layout_informations_gauche = new QVBoxLayout;
    layout_haut_gauche = new QHBoxLayout;

    // Création de la grid
    layout_batiments = new QGridLayout;
    layout_monuments = new QGridLayout;
    text_bat = new QLabel;
    text_bat->setText(QString::fromStdString("Batiments :"));
    layout_batiments->addWidget(text_bat, 0,0);
    int i = 0;
    int ind_bat;
    int ind_couleurs = 1;
    // Création des vues des batiments du joueur
    vue_batiments = new vector<VueCarte*>;
    for (auto& couleur : joueur->get_liste_batiment()){
        ind_bat = 0;
        for (auto bat : couleur.second){
            // Affichage du batiment
            vue_batiments->push_back(new VueCarte(*bat.first, true, parent));
            layout_batiments->addWidget((*vue_batiments)[i], ind_couleurs, ind_bat);
            connect((*vue_batiments)[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(batimentClique(VueCarte*)));
            ind_bat++;
            i++;
        }
        ind_couleurs++;
    }
    // Création d'un bouton donnant accès aux batiments fermés
    bat_ferme = new QPushButton("Batiment Fermes");
    layout_batiments->addWidget(bat_ferme);
    connect(bat_ferme, SIGNAL(clicked()),this, SLOT(affichage_bat_ferme()));



    // Création des vues des monuments du joueur
    vue_monuments = new vector<VueCarte*>;
    int ind_mon=0;
    for (auto& mon : joueur->get_liste_monument()){

        vue_monuments->push_back(new VueCarte(*mon.first,true, parent));
        layout_monuments->addWidget((*vue_monuments)[ind_mon], ind_mon/3, ind_mon%3);
        connect((*vue_monuments)[ind_mon],SIGNAL(carteClicked(VueCarte*)),this,SLOT(monumentClique(VueCarte*)));
        ind_mon++;
    }

    int ind_bat_ferme = 0;
    vue_batiments_ferme = new vector<VueCarte*>;
    // Ajout des batiments fermés à une nouvelle fenêtre
    fenetre_bat_fermes = new QWidget;
    layout_batiments_ferme = new QGridLayout(fenetre_bat_fermes);
    for (auto bat: joueur->get_liste_batiment_fermes()) {
        vue_batiments_ferme->push_back(new VueCarte(*bat, false, fenetre_bat_fermes));
        layout_batiments_ferme->addWidget((*vue_batiments_ferme)[ind_bat_ferme], i % 4, i / 4);
        ind_bat_ferme++;
    }

    // Création du layout gauche
    layout_haut_gauche->addWidget(nom_joueur);
    layout_haut_gauche->addWidget(argent);
    layout_informations_gauche->addLayout(layout_haut_gauche);
    layout_informations_gauche->addLayout(layout_monuments);

    // Ajout des layouts à la page d'informations
    layout_informations->addLayout(layout_informations_gauche);
    layout_informations->addLayout(layout_batiments);

    // Définition du layout principal
    setLayout(layout_informations);
}

void VueJoueur::batimentClique(VueCarte* vc){
    /// Slot lorsque la carte est cliquée
    // Création d'une nouvelle fenetre
    QWidget* fenetre = new QWidget();
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    // Affichage de la fenetre pop up
    fenetre->show();
}
void VueJoueur::monumentClique(VueCarte* vc){
    /// Slot lorsque la carte est cliquée
    // Création d'une nouvelle fenetre
    QWidget* fenetre = new QWidget();
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    if(get_est_joueur_actuel()){
        QPushButton *buttonAct = new QPushButton(fenetre);
        buttonAct->setText(QString::fromStdString("Acheter monument"));
    }

    // Affichage de la fenetre pop up
    fenetre->show();
}



void VueJoueur::affichage_bat_ferme(){
    /// Affichage de la fenetre avec les batiments fermés
    // Ouverture de la fenetre si elle est fermée
    fenetre_bat_fermes->show();
}

void update_monu(VueCarte* vc, Carte* c){
    vc->set_pixmap(c->get_path_image());
    vc->set_icon(vc->get_pixmap());
}

void replace_batiment(){

}

void VueJoueur::update_vue(){
    /// Mise à jour de la vue joueur
    // Mise à jour de l'argent
    if(joueur->get_argent() != get_widget_argent()->intValue()){
        replace_argent(joueur->get_argent());
    }
    // Mise à jour des batiments


    // Mise à jour des batiments fermés


    // Mise à jour des monuments
    map<Monument*, bool> mon = joueur->get_liste_monument();
    for(size_t i; i< mon.size();i++){

    }

}

