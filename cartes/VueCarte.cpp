#include <QLabel>
#include <QHBoxLayout>
#include "VueCarte.h"
#include "../joueur/Joueur.h"

VueCarte::VueCarte(const Carte &c, QWidget *parent) {
    /// Créer la vue d'une carte
    // Attributs du bouton
    setFlat(true);
    setAutoFillBackground(true);
    setFixedSize(40, 62);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
    // Nom du bouton
    this->setObjectName(c.get_nom());
    // Image du bouton
    QPixmap pixmap(QString::fromStdString(c.get_path_image()));
    pixmap.scaled(20,31,Qt::KeepAspectRatio);
    QIcon ButtonIcon(pixmap);
    this->setIconSize(QSize(40, 62));
    this->setIcon(ButtonIcon);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setAutoFillBackground(true);
    setFixedSize(80, 124);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}
