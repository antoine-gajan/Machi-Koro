#ifndef MACHI_KORO_VUECARTE_H
#define MACHI_KORO_VUECARTE_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include "Carte.h"
#include <iostream>

class VueCarte : public QPushButton
{
Q_OBJECT
public:
    VueCarte(const Carte& c, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(const Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    const Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }
private:
    const Carte* carte=nullptr;

signals:
    // quand la vue de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};


#endif //MACHI_KORO_VUECARTE_H