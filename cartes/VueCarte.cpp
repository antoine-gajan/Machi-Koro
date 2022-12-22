#include <QLabel>
#include <QHBoxLayout>
#include "VueCarte.h"
#include "../joueur/Joueur.h"

VueCarte::VueCarte(const Carte &c, bool etat, QWidget *parent) : QPushButton(parent),carte(&c){
    /// Créer la vue d'une carte
    // Si il est à afficher dans VueJoueur
    //
    carte = &c;
    path_carte = carte->get_path_image();
    if(etat){

        setFlat(true);
        setAutoFillBackground(true);
        setFixedSize(40, 62);
        connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
        setCheckable(true);
        // Nom du bouton
        this->setObjectName(QString::fromStdString(c.get_nom()));
        // Image du bouton
        pixmap = QPixmap(QString::fromStdString(path_carte));
        pixmap.scaled(20,31,Qt::KeepAspectRatio);
        ButtonIcon = QIcon(pixmap);
        this->setIconSize(QSize(40, 62));
        this->setIcon(ButtonIcon);
    }
    // S'il est à afficher dans une pop up (taille plus grande)
    else{
        setFlat(true);
        setAutoFillBackground(true);
        setFixedSize(120, 186);
        connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
        setCheckable(true);
        // Nom du bouton
        this->setObjectName(QString::fromStdString(c.get_nom()));
        // Image du bouton
        pixmap = QPixmap(QString::fromStdString(path_carte));
        pixmap.scaled(120,186,Qt::KeepAspectRatio);
        ButtonIcon = QIcon(pixmap);
        this->setIconSize(QSize(120, 186));
        this->setIcon(ButtonIcon);
    }
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setAutoFillBackground(true);
    setFixedSize(80, 124);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}
