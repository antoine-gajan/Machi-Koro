#include <iostream>
using namespace std;

#include <QApplication>
#include <QPushButton>
#include "VueCarte.h"
#include "VueJoueur.h"
#include "Joueur.h"
#include "Boulangerie.h"
#include "Aeroport.h"

int main(int argc, char * argv[]) {

    QApplication app(argc, argv);
    QWidget fenetre;
    vector<Batiment*> liste_bat;
    liste_bat.push_back(new Boulangerie());
    vector<Monument*> liste_mon;
    liste_mon.push_back(new Aeroport());
    Joueur* j = new Joueur("Test", liste_mon, liste_bat, 3);
    VueJoueur* vj = new VueJoueur(j, &fenetre);
    vj->show();
    fenetre.show();
    return app.exec();
}