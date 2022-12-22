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
#include <QLayoutItem>
#include "Joueur.h"
#include "Boulangerie.h"
#include "Aeroport.h"
#include "Epicerie.h"
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QFormLayout>
#include <QLineEdit>
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

void resize_and_center(QWidget *widget, int width, int height)
{
    widget->resize(width, height);
    widget->move(QApplication::primaryScreen()->geometry().center() - widget->rect().center());
}

void launch_menu_2(QApplication *app, const string &edition_name, const list<string> &extensions){

    EditionDeJeu * edition;
    vector<EditionDeJeu *> listing_extension;

    edition = new EditionDeJeu(edition_name);

    for (const auto & extension : extensions){
        cout << "Extension : " << extension << endl;
        listing_extension.push_back(new EditionDeJeu(extension));
    }


    unsigned int max_joueurs = edition->get_nb_joueurs_max();
    unsigned int nb_monuments_win = edition->get_nb_monuments_win();
    for (const auto & extension : listing_extension){
        if (extension->get_nb_joueurs_max() > max_joueurs){
            max_joueurs = extension->get_nb_joueurs_max();
        }
        if (extension->get_nb_monuments_win() > nb_monuments_win){
            nb_monuments_win = extension->get_nb_monuments_win();
        }
    }

    auto list_batiments = edition->get_batiment();
    unsigned int nb_batiments_differents = list_batiments.size();


    for (const auto & extension : listing_extension){
        for (const auto & batiment : extension->get_batiment()){

            string nom = batiment.first->get_nom();
            bool found = false;

            for (const auto & batiment2 : list_batiments){
                if (batiment2.first->get_nom() == nom){
                    found = true;
                    break;
                }
            }

            if (!found){
                list_batiments[batiment.first] = batiment.second;
                nb_batiments_differents++;
            }
        }
    }

    cout << "nb_batiments_differents = " << nb_batiments_differents << endl;

    delete edition;
    for (const auto & extension : listing_extension){
        delete extension;
    }


//    pas 2 joueurs même nom
// taille shop ou extended

//    auto *menu = new QWidget();
//    resize_and_center(menu, 500, 180);

//    menu->setContentsMargins(50, 30, 50, 50);

    auto *window = new QDialog();

    window->setWindowTitle("Machi Koro - Menu");
    window->setContentsMargins(50, 30, 50, 50);

    auto *label = new QLabel("Choisissez le nombre de joueurs :");

    auto *spinBox = new QSpinBox;
    spinBox->setRange(2, (int) max_joueurs);
    spinBox->setValue(2);

    auto *formLayout = new QFormLayout;
    for (int i = 0; i < spinBox->value(); i++) {
        auto *lineEdit = new QLineEdit;
        formLayout->addRow(QString("Nom du joueur %1 :").arg(i + 1), lineEdit);
    }

    auto *layout = new QVBoxLayout;
    auto *h_layout = new QHBoxLayout;
    h_layout->addWidget(label);
    h_layout->addWidget(spinBox);
    layout->addLayout(h_layout);
    layout->addLayout(formLayout);

    auto *validateButton = new QPushButton("Valider");
    layout->addWidget(validateButton);

    window->setLayout(layout);


    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [formLayout](int value) {

        while (formLayout->rowCount() > 0) {
            formLayout->removeRow(0);
        }

        for (int i = 0; i < value; i++) {
            auto *lineEdit = new QLineEdit;
            formLayout->addRow(QString("Nom du joueur %1 :").arg(i + 1), lineEdit);
        }

    });

    QObject::connect(validateButton, &QPushButton::clicked, [formLayout]() {
        // Parcours des widgets du formulaire et récupération de leurs valeurs
        for (int i = 0; i < formLayout->rowCount(); i++) {
            auto *lineEdit = qobject_cast<QLineEdit*>(formLayout->itemAt(i, QFormLayout::FieldRole)->widget());
            if (lineEdit) {
                QString value = lineEdit->text();
                cout << "Nom du joueur " << i + 1 << " : " << value.toStdString() << endl;
                // Utilisation de la valeur récupérée
                // ...
            }
        }
    });


    window->show();
}

void validate_menu(QWidget *menu, QApplication *app, const string &edition, const list<string> &extensions){
    cout << "Edition: " << edition << endl;
    cout << "Extensions: " << endl;
    for (const auto & extension : extensions){
        cout << extension << endl;
    }
    cout << "Validation du menu" << endl;

    menu->close();

    launch_menu_2(app, edition, extensions);
}


void launch_menu_1(QApplication *app){

    auto *menu = new QWidget();
    resize_and_center(menu, 500, 180);


    menu->setContentsMargins(50, 30, 50, 50);
    auto *gridLayout = new QGridLayout;


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
    editionCombo->setMinimumWidth(200);

    item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled);

    editionCombo->setModel(model);

    gridLayout->addWidget(editionLabel, 0, 0);
    gridLayout->addWidget(editionCombo, 0, 1);

    gridLayout->addItem(new QSpacerItem(0, 15), 1, 0);

    auto *extensionLabel = new QLabel("Choix des extension(s) :");
    gridLayout->addWidget(extensionLabel, 2, 0);

    auto *layout_h1 = new QHBoxLayout;
    auto *label_vide1 = new QLabel();
    label_vide1->setFixedWidth(5);
    auto *greenValleyCheck = new QCheckBox("Green valley");
    layout_h1->addWidget(label_vide1);
    layout_h1->addWidget(greenValleyCheck);

    auto *layout_h2 = new QHBoxLayout;
    auto *label_vide2 = new QLabel();
    label_vide2->setFixedWidth(5);
    auto *marinaCheck = new QCheckBox("Marina");
    layout_h2->addWidget(label_vide2);
    layout_h2->addWidget(marinaCheck);

    greenValleyCheck->setEnabled(true);
    marinaCheck->setEnabled(true);

    gridLayout->addLayout(layout_h1, 2, 1);
    gridLayout->addLayout(layout_h2, 3, 1);

    gridLayout->addItem(new QSpacerItem(0, 15), 4, 0);

    auto *validateButton = new QPushButton("Valider");
    validateButton->setFixedWidth(200);

    auto *cancelButton = new QPushButton("Annuler");
    cancelButton->setFixedWidth(200);

    gridLayout->addWidget(validateButton, 5, 0, Qt::AlignCenter);
    gridLayout->addWidget(cancelButton, 5, 1, Qt::AlignCenter);

    QObject::connect(cancelButton, &QPushButton::clicked, app, &QApplication::quit);

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

    // le bouton valider fait appel à la fonction validate_menu
    QObject::connect(validateButton, &QPushButton::clicked, [menu, app, editionCombo, greenValleyCheck, marinaCheck](){
        string edition = editionCombo->currentText().toStdString();
        list<string> extensions;
        if (greenValleyCheck->isChecked()){
            extensions.emplace_back("GreenValley");
        }
        if (marinaCheck->isChecked()){
            extensions.emplace_back("Marina");
        }
        validate_menu(menu, app, edition, extensions);
    });

    menu->setLayout(gridLayout);
    menu->setWindowTitle("Machi Koro - Menu");

    menu->show();
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
    auto *jeu = new QWidget();

    launch_menu_1(&app);

    /*resize_and_center(jeu, 1000, 700);
    build_content_jeu(jeu);
    jeu->show();*/

//    QWidget fenetre;
//    VuePartie* vp = new VuePartie(nullptr, &fenetre);
//    vp->show();
    //fenetre.show();
    QApplication::exec();

    cout << "Fin du programme" << endl;
    return 0;
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