#include "VuePioche.h"

VuePioche::VuePioche(Pioche& pioche, QWidget *parent) {

    if(pioche.get_top_carte() == nullptr){
        pioche_exception = new QLabel;
        pioche_exception->setText("Pioche vide!");
        this->addWidget(pioche_exception,33);
    }else{
        VueCarte* view_pioche = new VueCarte(*(pioche.get_top_carte()),true);
        this->addWidget(view_pioche,33);
    }

    unsigned int nb_cartes_start = pioche.get_taille();//on initialise l'attribut avce le nombre max de cartes qu'on pourra avoir dans la pioche c'est à dire au début

    barre_pioche = new QProgressBar;
    barre_pioche->setRange(0,nb_cartes_start);
    barre_pioche->setValue(pioche.get_taille());//valeur que l'on devra mettre à jour à chaque fois qu'on pioche une carte
    barre_pioche->setFixedWidth(300);
    this->addWidget(barre_pioche,33);
}
