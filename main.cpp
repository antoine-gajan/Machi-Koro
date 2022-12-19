#include <iostream>
using namespace std;
#include <QApplication>
#include <QtGui/QScreen>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QVBoxLayout>
#include "VueCarte.h"
#include "VueJoueur.h"
#include "Joueur.h"
#include "Boulangerie.h"
#include "Aeroport.h"
#include "Epicerie.h"
#include "Cafe.h"

void resize_and_center(QWidget *widget, int width, int height)
{
    widget->resize(width, height);
    widget->move(QApplication::primaryScreen()->geometry().center() - widget->rect().center());
}

void build_content_menu(QWidget *menu){
    auto *layout_menu = new QGridLayout;

    auto *bouton1 = new QPushButton("Jouer", menu);
    bouton1->move(100, 100);

    auto *bouton2 = new QPushButton("Options", menu);
    bouton2->move(100, 200);

    menu->setWindowTitle("Machi Koro - Menu");
}

void build_content_jeu(QWidget *jeu){

    auto *main_layout = new QVBoxLayout(jeu);

    auto *layout_entete = new QHBoxLayout();
    auto label_entete = new QLabel("Ici entete");
    layout_entete->addWidget(label_entete);

    auto *layout_centre = new QHBoxLayout();
    auto *layout_centre_gauche = new QVBoxLayout(); // Pioche et affichages

    // build_content_centre_gauche(layout_centre_gauche);
    auto label_centre_gauche = new QLabel("Ici pioche");
    layout_centre_gauche->addWidget(label_centre_gauche);

    auto *layout_centre_droite = new QVBoxLayout(); // Shop
    auto label_centre_droite = new QLabel("Ici shop");
    // build_content_centre_droite(layout_centre_droite);
    layout_centre_droite->addWidget(label_centre_droite);
    layout_centre->addLayout(layout_centre_gauche);
    layout_centre->addLayout(layout_centre_droite);


    auto *layout_joueur = new QHBoxLayout();
    auto *layout_joueur_gauche = new QVBoxLayout(); // Infos joueur, monuments, argent, etc

    // build_content_joueur_gauche(layout_joueur_gauche);
    auto label_joueur_gauche = new QLabel("Ici infos joueur");
    layout_joueur_gauche->addWidget(label_joueur_gauche);

    auto *layout_joueur_droite = new QVBoxLayout(); // Batiments et bouton batiments fermes
    // build_content_joueur_droite(layout_joueur_droite);

    auto label_joueur_droite = new QLabel("Ici batiments");
    layout_joueur_droite->addWidget(label_joueur_droite);
    layout_joueur->addLayout(layout_joueur_gauche);
    layout_joueur->addLayout(layout_joueur_droite);

    main_layout->addLayout(layout_entete);
    main_layout->addLayout(layout_centre);
    main_layout->addLayout(layout_joueur);

    jeu->setLayout(main_layout);

    jeu->setWindowTitle("Machi Koro - Jeu");
}

int main(int argc, char * argv[]) {

    QApplication app(argc, argv);
    /*auto *menu = new QWidget();
    auto *jeu = new QWidget();

    resize_and_center(menu , 700, 500);
    build_content_menu(menu);
    menu->show();


    resize_and_center(jeu, 1000, 700);
    build_content_jeu(jeu);
    jeu->show();


    return QApplication::exec();*/

    QWidget fenetre;
    vector<Batiment*> liste_bat;
    liste_bat.push_back(new Boulangerie());
    liste_bat.push_back(new Epicerie());
    liste_bat.push_back(new Cafe());
    vector<Monument*> liste_mon;
    //liste_mon.push_back(new Aeroport());
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    VueJoueur* vj = new VueJoueur(j, &fenetre);
    vj->show();
    //fenetre.show();

    //QHBoxLayout * layout = new QHBoxLayout;
    //QLabel* lab = new QLabel(&fenetre);
    //lab->setPixmap(QPixmap(":/Boulangerie.jpg"));
    //QPushButton* button = new QPushButton;
    //QLabel *label = new QLabel(&fenetre);
    //QPixmap pixmap("../assets/batiments/Vert/Boulangerie.png");
    //label->setPixmap(pixmap);
    //label->resize(pixmap.size());
    //QIcon ButtonIcon(pixmap);
    //button->setIcon(ButtonIcon);
    //button->setIconSize(pixmap.rect().size());

    //fenetre.show();

    return app.exec();
}