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

    //Affichage de la pioche

    //Batiment *b = new Boulangerie();
    //Batiment *bat2 = new Epicerie();

    pioche = new QHBoxLayout;
    if(partie->get_pioche()->get_top_carte() == nullptr){
        pioche_exception = new QLabel;
        pioche_exception->setText("Pioche vide!");
        pioche->addWidget(pioche_exception,33);
    }else{
        VueCarte* view_pioche = new VueCarte(*(partie->get_pioche()->get_top_carte()),true);
        pioche->addWidget(view_pioche,33);
    }

    /*
    VueCarte* view_pioche = new VueCarte(*b,true);
    body->addWidget(view_pioche);
*/
    //Affichage du shop
    shop = new QGridLayout;
    //nous voulons ici calculer la taille du shop.
    unsigned int largeur = round(sqrt(partie->get_shop()->get_nb_tas_max()));

    unsigned int x = 0;
    unsigned int y = 1;
    unsigned int compteur=0;

    for(auto &it : partie->get_shop()->get_contenu()){
        tab_vue_shop.push_back(new VueCarte(*(it.first),true));

        connect((tab_vue_shop)[compteur],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
        shop->addWidget((tab_vue_shop)[compteur],x,y-1);
        if(it.second>1){
            tab_vue_shop[compteur]->update();
            //QPainter* painter = new QPainter(tab_vue_shop[compteur]);
            //painter->begin(tab_vue_shop[compteur]);
            //painter->drawText(0,0,QString::fromStdString(to_string(it.second)));
            //painter->end();
            //QPaintEvent* event = new QPaintEvent((tab_vue_shop)[compteur]->rect());
            //(tab_vue_shop)[compteur]->paintEvent(event);
        }
        if(y%largeur == 0){
            x ++;
            y = 1;
        }else{
            y++;
        }
        compteur++;
    }

    body->addLayout(pioche,1);
    body->addLayout(shop,100);

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

    /*vector<Batiment*> liste_bat;

    liste_bat.push_back(b);
    //liste_bat.push_back(new Boulangerie());
    liste_bat.push_back(bat2);
    liste_bat.push_back(new Cafe());
    vector<Monument*> liste_mon;
    Monument* mon = new TourRadio();
    mon->activer();*/
    /*vector<Joueur*> j = partie->get_tab_joueurs();
    for(size_t i = 0; i<j.size(); i++){
        tab_vue_joueurs.push_back(new VueJoueur(j[i], parent));
    }*/



    /*liste_mon.push_back(mon);
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    j->fermer_batiment(b);
    Joueur* j2 = new Joueur("Test2", liste_mon, liste_bat, 45);
    tab_j.push_back(j);
    tab_j.push_back(j2);
    // Ajout des vues joueurs
    tab_vue_joueurs.push_back(new VueJoueur(j, parent));
    tab_vue_joueurs.push_back(new VueJoueur(j2, parent));

    //Mettre les joueurs dans des stacks
    nb_joueurs = tab_vue_joueurs.size();
    joueur_affiche = 0;*/

    // Ajout de toutes les vues joueurs à un QStackWidget
    /*stack = new QStackedWidget(parent);
    for(auto vj : tab_vue_joueurs){
        stack->addWidget(vj);
    }
    stack->setCurrentIndex(0);*/


    // Boutons de navigation gauche et droite dans les Vues Joueurs
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));

    layout = new QHBoxLayout();

    layout->addWidget(b1);
    //layout->addWidget(stack);
    //layout->addWidget(tab_vue_joueurs[joueur_affiche]);

    nb_joueurs = partie->get_tab_joueurs().size();
    joueur_affiche = 0;
    vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche], parent);
    layout->addWidget(vue_joueur);
    //vj = tab_vue_joueurs[1];
    //layout->replaceWidget(tab_vue_joueurs[i], tab_vue_joueurs[1]);
    layout->addWidget(b2);
    //j->fermer_batiment(bat2);
    //j->set_argent(24);


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
    vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche], parent_fenetre);
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
    vue_joueur = new VueJoueur(partie_actuelle->get_tab_joueurs()[joueur_affiche], parent_fenetre);
    // Remplacement par la nouvelle
    layout->replaceWidget(old, vue_joueur);
    delete old;
    // Mise à jour de l'affichage
    update();
}

void VuePartie::carteClique(VueCarte* vc){
    /// Slot lorsque la carte est cliquée
    // Création d'une nouvelle fenetre
    QWidget* fenetre = new QWidget();
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(parent_fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    //std::cout<<vc->getCarte().get_nom()<<endl;
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    // Affichage de la fenetre pop up
    fenetre->show();
}


