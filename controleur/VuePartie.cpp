#include <iostream>
#include <string>
using namespace std;
#include "VuePartie.h"
#include "Partie.h"

VuePartie::VuePartie(Partie *partie, QWidget *parent){

    structure = new QVBoxLayout();

    //Création de l'entete de la page (pourquoi pas créer une classe VueEntete?)

    entete = new QHBoxLayout();

    //Affichage du nom de l'édition de jeu

    label_edj = new QLabel;
    label_edj->setText("Nom de l'édition de jeu");// à voir avec l'équipe si on ajoute des attributs dans partie pour avoir ces infos de display)

    entete->addWidget(label_edj);

    //Affichage du nom du joueur actuel
    label_joueur_actuel = new QLabel;
    string nom_joueur = "Joueur actuel : ";
    //nom_joueur += partie->get_tab_joueurs()[partie->get_joueur_actuel()]->get_nom();
    nom_joueur += "nom du joueur";
    label_joueur_actuel->setText(QString::fromStdString(nom_joueur));
    entete->addWidget(label_joueur_actuel);

    structure->addLayout(entete);

    //Affichage de la valeur des dés

    display_des = new QVBoxLayout;

    label_de1 = new QLabel;
    //label_de1->setText(QString::fromStdString((string)partie->get_de_1()));
    label_de1->setText("valeur de1");
    display_des->addWidget(label_de1);

    label_de2 = new QLabel;
    //label_de2->setText(QString::fromStdString((string)partie->get_de_2()));
    label_de2->setText("valeur de2");
    display_des->addWidget(label_de2);

    entete->addLayout(display_des);

    ///Affichage du Shop et de la Pioche (va falloir créer deux classes vue shop et vue pioche certainement)

    body = new QHBoxLayout;

    //Affichage de la pioche

    Batiment *b = new Boulangerie();
    Batiment *bat2 = new Epicerie();


    if(partie->get_pioche()->get_top_carte() == nullptr){
        pioche_exception = new QLabel;
        pioche_exception->setText("Pioche vide!");
        body->addWidget(pioche_exception);
    }else{
        VueCarte* view_pioche = new VueCarte(*(partie->get_pioche()->get_top_carte()),true);
        body->addWidget(view_pioche);
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

    for(auto &it : partie->get_shop()->get_contenu()){
        shop->addWidget(new VueCarte(*(it.first),true),x,y-1);
        if(y%largeur == 0){
            x ++;
            y = 1;
        }else{
            y++;
        }
    }

    body->addLayout(shop);

    structure->addLayout(body);
    /*auto *menu = new QWidget();
    auto *jeu = new QWidget();

    resize_and_center(menu , 700, 500);
    build_content_menu(menu);
    menu->show();


    resize_and_center(jeu, 1000, 700);
    build_content_jeu(jeu);
    jeu->show();


    return QApplication::exec();*/

    vector<Batiment*> liste_bat;

    liste_bat.push_back(b);
    //liste_bat.push_back(new Boulangerie());
    liste_bat.push_back(bat2);
    liste_bat.push_back(new Cafe());
    vector<Monument*> liste_mon;
    Monument* mon = new TourRadio();
    mon->activer();
    liste_mon.push_back(mon);
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    j->fermer_batiment(b);
    Joueur* j2 = new Joueur("Test2", liste_mon, liste_bat, 45);
    tab_j.push_back(j);
    tab_j.push_back(j2);
    // Ajout des vues joueurs
    tab_vue_joueurs.push_back(new VueJoueur(j, parent));
    tab_vue_joueurs.push_back(new VueJoueur(j2, parent));
    nb_joueurs = tab_vue_joueurs.size();
    joueur_affiche = 0;

    // Ajout de toutes les vues joueurs à un QStackWidget
    stack = new QStackedWidget(parent);
    for(auto vj : tab_vue_joueurs){
        stack->addWidget(vj);
    }
    stack->setCurrentIndex(0);


    // Boutons de navigation gauche et droite dans les Vues Joueurs
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));

    layout = new QHBoxLayout();

    layout->addWidget(b1);
    layout->addWidget(stack);
    //layout->addWidget(tab_vue_joueurs[joueur_affiche]);


    //vj = tab_vue_joueurs[1];
    //layout->replaceWidget(tab_vue_joueurs[i], tab_vue_joueurs[1]);
    layout->addWidget(b2);
    j->fermer_batiment(bat2);
    j->set_argent(24);
    structure->addLayout(layout);
    setLayout(structure);

}


void VuePartie::d_click(){
    /// Slot bouton droit
    /*// Clean
    delete stack;
    tab_vue_joueurs.clear();
    // Ajout des nouvelles vues joueurs
    for (auto joueur : tab_j){
        tab_vue_joueurs.push_back(new VueJoueur(joueur, parent));
    }
    // Ajout des widgets
    stack = new QStackedWidget;
    for (auto vj : tab_vue_joueurs){
        stack->addWidget(vj);
    }*/
    // MAJ des indices
    //tab_vue_joueurs[joueur_affiche+1%nb_joueurs]->replace_argent(5);
    stack->setCurrentIndex((joueur_affiche + 1) % nb_joueurs);
    VueJoueur* vj = (VueJoueur*)stack->currentWidget();
    vj->update_vue();
    joueur_affiche = (joueur_affiche + 1) % nb_joueurs;


    //update();
}


void VuePartie::g_click(){
    /// Slot bouton gauche
    /*// Clean
    delete stack;
    tab_vue_joueurs.clear();
    // Ajout des nouvelles vues joueurs
    for (auto joueur : Partie::get_instance()->get_tab_joueurs()){
        tab_vue_joueurs.push_back(new VueJoueur(joueur, parent));
    }
    // Ajout des widgets
    stack = new QStackedWidget;
    for (auto vj : tab_vue_joueurs){
        stack->addWidget(vj);
    }*/
    // MAJ des indices
    stack->setCurrentIndex((joueur_affiche - 1) % nb_joueurs);
    joueur_affiche = (joueur_affiche - 1) % nb_joueurs;
    //update();
}


