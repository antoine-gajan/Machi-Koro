#include <QStyleFactory>
#include "VuePioche.h"
#include "Partie.h"

VuePioche::VuePioche(Pioche& pioche, QWidget *parent) {

    if(pioche.get_top_carte() == nullptr){
        pioche_exception = new QLabel;
        pioche_exception->setText("Pioche vide!");
        this->addWidget(pioche_exception,33);
    }else{
        QLabel* back_carte = new QLabel;
        QPixmap img(QString::fromStdString("../assets/batiments/BACK-cartes.png"));
        img = img.scaled(120,186,Qt::KeepAspectRatio);
        back_carte->setPixmap(img);
        back_carte->setFixedSize(120,186);
        this->addWidget(back_carte,33);
    }


    barre_pioche = new QProgressBar;
    barre_pioche->setRange(0,(int)pioche.get_taille_init());
    barre_pioche->setValue((int)pioche.get_taille());//valeur que l'on devra mettre à jour à chaque fois qu'on pioche une carte
    barre_pioche->setFixedWidth(300);
    barre_pioche->setStyle(QStyleFactory::create("Fusion"));
    this->addWidget(barre_pioche,33);
}

void VuePioche::update() {
    barre_pioche->setValue((int)Partie::get_instance()->get_pioche()->get_taille());
    if (Partie::get_instance()->get_pioche()->get_taille() == 0) {
        pioche_exception = new QLabel;
        pioche_exception->setText("Pioche vide!");
        this->addWidget(pioche_exception,33);
    }
    else {
        QLabel* back_carte = new QLabel;
        QPixmap img(QString::fromStdString("../assets/batiments/BACK-cartes.png"));
        img = img.scaled(120,186,Qt::KeepAspectRatio);
        back_carte->setPixmap(img);
        back_carte->setFixedSize(120,186);
        this->addWidget(back_carte,33);
    }
}