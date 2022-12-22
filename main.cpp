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
#include <QWidget>
#include "VueJoueur.h"
#include "Joueur.h"
#include "Boulangerie.h"
#include "Aeroport.h"
#include "Epicerie.h"
#include "Cafe.h"
#include "VuePartie.h"
#include <QComboBox>
#include <QCheckBox>
#include <QApplication>
#include <QComboBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QApplication>
#include <QComboBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include "Partie.h"

void resize_and_center(QWidget *widget, int width, int height)
{
    widget->resize(width, height);
    widget->move(QApplication::primaryScreen()->geometry().center() - widget->rect().center());
}


void build_content_menu(QWidget *menu){
    auto* form = new QFormLayout(menu);

    auto *editionLabel = new QLabel("Choix de l'édition :");
    auto* editionCombo = new QComboBox();

    auto *model = new QStandardItemModel();
    auto *item1 = new QStandardItem("-- Veuillez choisir une option --");
    auto *item2 = new QStandardItem("Standard");
    auto *item3 = new QStandardItem("Deluxe");
    auto *item4 = new QStandardItem("Custom");

    model->appendRow(item1);
    model->appendRow(item2);
    model->appendRow(item3);
    model->appendRow(item4);

    editionCombo->setCurrentIndex(0);

    item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled);

    editionCombo->setModel(model);

    form->addRow(editionLabel, editionCombo);

    auto *greenValleyCheck = new QCheckBox("Green valley");
    auto *marinaCheck = new QCheckBox("Marina");

    greenValleyCheck->setEnabled(true);
    marinaCheck->setEnabled(true);

    form->addRow(greenValleyCheck);
    form->addRow(marinaCheck);

    auto *validateButton = new QPushButton("Valider");
    auto *cancelButton = new QPushButton("Annuler");

    form->addRow(validateButton, cancelButton);

    QObject::connect(editionCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [greenValleyCheck, marinaCheck](int index) {
                         if (index == 1) { // Si l'index sélectionné est Standard
                             greenValleyCheck->setEnabled(true);
                             marinaCheck->setEnabled(true);
                         } else {
                             greenValleyCheck->setEnabled(false);
                             greenValleyCheck->setChecked(false);
                             marinaCheck->setEnabled(false);
                             marinaCheck->setChecked(false);
                         }
                     });

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
    menu->show();*/


    /*resize_and_center(jeu, 1000, 700);
    build_content_jeu(jeu);
    jeu->show();*/
    QWidget fenetre;
    Partie* partie = Partie::get_instance();
    VuePartie* vp = new VuePartie(partie, &fenetre);
    vp->show();
    //fenetre.show();
    return QApplication::exec();

    /*QWidget fenetre;
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
    VueJoueur* vj = new VueJoueur(j, &fenetre);
    vj->show();*/
    //fenetre.show();

    //QHBoxLayout * layout = new QHBoxLayout;
    //QLabel* lab = new QLabel(&fenetre);
    //lab->setPixmap(QPixmap(":/Boulangerie.png"));
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