#include <iostream>
using namespace std;

#include <QApplication>
#include <QPushButton>
#include "VueCarte.h"
#include "Boulangerie.h"

int main(int argc, char * argv[]) {

    QApplication app(argc, argv);
    QWidget fenetre;

    fenetre.setFixedSize(500, 300);
    fenetre.setWindowTitle("Machi Koro");
    VueCarte *carte = new VueCarte(Boulangerie(), &fenetre);
    carte->show();
    fenetre.show();
    return app.exec();
}