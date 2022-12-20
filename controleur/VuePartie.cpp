#include <iostream>
using namespace std;
#include "VuePartie.h"


VuePartie::VuePartie(QWidget *parent){

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
    liste_bat.push_back(b);
    //liste_bat.push_back(new Boulangerie());
    liste_bat.push_back(new Epicerie());
    liste_bat.push_back(new Cafe());
    vector<Monument*> liste_mon;
    Monument* mon = new Aeroport();
    mon->activer();
    liste_mon.push_back(mon);
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    j->fermer_batiment(b);
    Joueur* j2 = new Joueur("Theo", liste_mon, liste_bat, 45);
    tab_vue_joueurs.push_back(new VueJoueur(j, parent));
    tab_vue_joueurs.push_back(new VueJoueur(j2, parent));
    nb_joueurs = tab_vue_joueurs.size();
    joueur_affiche = 0;
    //VueJoueur* vj = new VueJoueur(tab_joueurs[i], &fenetre);
    //VueJoueur* vj = tab_vue_joueurs[i];
    QPushButton* b1 = new QPushButton(parent);
    b1->setText(QString::fromStdString("(<)"));
    connect(b1, SIGNAL(clicked()),this, SLOT(g_click()));
    QPushButton* b2 = new QPushButton(parent);
    b2->setText(QString::fromStdString("(>)"));
    connect(b2, SIGNAL(clicked()),this, SLOT(d_click()));
    layout = new QHBoxLayout(parent);
    layout->addWidget(b1);
    layout->addWidget(tab_vue_joueurs[joueur_affiche]);

    //vj = tab_vue_joueurs[1];
    //layout->replaceWidget(tab_vue_joueurs[i], tab_vue_joueurs[1]);
    layout->addWidget(b2);
    setLayout(layout);

}


void VuePartie::d_click(){
    /*if(joueur_affiche == nb_joueurs-1){
        layout->replaceWidget(tab_vue_joueurs[joueur_affiche], tab_vue_joueurs[0]);
        joueur_affiche = 0;
    }
    else{
        layout->replaceWidget(tab_vue_joueurs[joueur_affiche], tab_vue_joueurs[joueur_affiche+1]);
        joueur_affiche++;
    }
    setLayout(layout);*/
}

void VuePartie::g_click(){
    /*if(joueur_affiche == 0){
        layout->replaceWidget(tab_vue_joueurs[joueur_affiche], tab_vue_joueurs[nb_joueurs-1]);
        joueur_affiche = nb_joueurs-1;
    }
    else{
        layout->replaceWidget(tab_vue_joueurs[joueur_affiche], tab_vue_joueurs[joueur_affiche-1]);
        joueur_affiche--;
    }
    setLayout(layout);*/
}
