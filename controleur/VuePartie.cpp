#include <iostream>
using namespace std;
#include "VuePartie.h"
#include "Partie.h"


VuePartie::VuePartie(Partie *partie, QWidget *parent){

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
    Batiment *b = new Boulangerie();
    Batiment *bat2 = new Epicerie();
    liste_bat.push_back(b);
    //liste_bat.push_back(new Boulangerie());
    liste_bat.push_back(bat2);
    liste_bat.push_back(new Cafe());
    vector<Monument*> liste_mon;
    Monument* mon = new Aeroport();
    mon->activer();
    liste_mon.push_back(mon);
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    j->fermer_batiment(b);
    Joueur* j2 = new Joueur("Theo", liste_mon, liste_bat, 45);
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
    layout = new QHBoxLayout(parent);
    layout->addWidget(b1);
    layout->addWidget(stack);
    //layout->addWidget(tab_vue_joueurs[joueur_affiche]);


    //vj = tab_vue_joueurs[1];
    //layout->replaceWidget(tab_vue_joueurs[i], tab_vue_joueurs[1]);
    layout->addWidget(b2);
    j->fermer_batiment(bat2);
    j->set_argent(24);
    setLayout(layout);

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
    vj->replace_argent(456);
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

void update(Joueur* j, VueJoueur* vj){
    if(j->get_argent() != vj->get_widget_argent()->intValue()){
        vj->replace_argent(j->get_argent());
    }

}
