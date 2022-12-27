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
public:

    VueShop(Shop& shop, QWidget *parent = nullptr);
public slots:
    void batiment_clique(VueCarte* vc);
};


#endif //MACHI_KORO_VUESHOP_H