#include "VueShop.h"

VueShop::VueShop(Shop &shop, QWidget *parent) {

    //nous voulons ici calculer la taille du shop.
    unsigned int largeur = round(sqrt(shop.get_nb_tas_max()));

    unsigned int x = 0;
    unsigned int y = 1;
    unsigned int compteur=0;

    for(auto &it : shop.get_contenu()){
        tab_vue_shop.push_back(new VueCarte(*(it.first),true));

        connect((tab_vue_shop)[compteur],SIGNAL(carteClicked(VueCarte*)),this,SLOT(batiment_clique(VueCarte*)));
        this->addWidget((tab_vue_shop)[compteur],x,y-1);
        if(it.second>1){
            // cas où on a plusieurs cartes identiques les unes sur les autres
            tab_vue_shop[compteur]->update();
            //QPainter* painter = new QPainter(tab_vue_shop[compteur]);
            //painter->begin(tab_vue_shop[compteur]);
            //painter->drawText(0,0,QString::fromStdString(to_string(it.second)));
            //painter->end();
            //QPaintEvent* event = new QPaintEvent((tab_vue_shop)[compteur]->rect());
            //(tab_vue_shop)[compteur]->paintEvent(event);
        }
        if(y%largeur == 0){
            x ++;
            y = 1;
        }else{
            y++;
        }
        compteur++;
    }
}

void VueShop::batiment_clique(VueCarte *vc) {
    /// Slot lorsque la carte est cliquée
    // Création d'une nouvelle fenetre
    QWidget* fenetre = new QWidget();
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    //std::cout<<vc->getCarte().get_nom()<<endl;
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    // Affichage de la fenetre pop up
    fenetre->show();

    /*
    /// Slot lorsque la carte est cliquée
    // Création d'une nouvelle fenetre
    QWidget* fenetre = new QWidget();
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte().get_path_image()));
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    if(get_est_joueur_actuel()){
        QPushButton *buttonAct = new QPushButton(fenetre);
        buttonAct->setText(QString::fromStdString("Acheter monument"));
    }

    // Affichage de la fenetre pop up
    fenetre->show();*/
}

