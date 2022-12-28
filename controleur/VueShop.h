#ifndef MACHI_KORO_VUESHOP_H
#define MACHI_KORO_VUESHOP_H

#include <QWidget>
#include "Shop.h"
#include "VueCarte.h"
#include <QGridLayout>

class VueShop  : public QGridLayout{
    Q_OBJECT
    vector<VueCarte *> tab_vue_shop;
    VueCarte *carte_choisie;
    unsigned int largeur;
    QPushButton* bouton_acheter;

public:

    VueShop(Shop& shop, QWidget *parent = nullptr);
    void update();
    VueCarte* get_carte_choisie() const {return carte_choisie;}
    void set_bouton_acheter() {bouton_acheter->setEnabled(true);}

public slots:
    void clicked_acheter_event();//VueCarte* vc);
    void batiment_clique(VueCarte* vc);
};


#endif //MACHI_KORO_VUESHOP_H
