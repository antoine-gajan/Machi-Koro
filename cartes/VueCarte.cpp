#include "VueCarte.h"

//  A ADAPTER //
VueCarte::VueCarte(const Carte &c, QWidget *parent) {
    /// Créer la vue d'une carte
    // Attributs du bouton
    setAutoFillBackground(true);
    setFixedSize(400, 620);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
    // Nom du bouton
    this->setObjectName(c.get_nom());
    setText(QString::fromStdString(c.get_nom()));
    // Image du bouton (ne marche pas)
    //QPixmap pixmap = QPixmap::fromImage(QImage(QString::fromStdString(c.get_path_image())));
    //this->setIcon(QIcon(QString::fromStdString(c.get_path_image())));
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setAutoFillBackground(true);
    setFixedSize(80, 124);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}
