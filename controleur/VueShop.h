#ifndef MACHI_KORO_VUESHOP_H
#define MACHI_KORO_VUESHOP_H

#include <QWidget>
#include "Shop.h"
#include "VueCarte.h"
#include "VuePartie.h"
#include <QGridLayout>

class VueShop  : public QGridLayout{
    Q_OBJECT
    vector<VueCarte *> tab_vue_shop;
    unsigned int largeur;
    QPushButton* bouton_acheter;

public:

    VueShop(Shop& shop, QWidget *parent = nullptr);
    void update();

public slots:
    //void clicked_acheter_event() {};
    void batiment_clique(VueCarte* vc);
};


#endif //MACHI_KORO_VUESHOP_H
