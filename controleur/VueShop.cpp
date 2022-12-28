#include "VueShop.h"
#include "Partie.h"


VueShop::VueShop(Shop &shop, QWidget *parent) {
    /// Calcul de la dimension de la grille
    largeur = floor(sqrt(shop.get_nb_tas_reel()));

    unsigned int x = 0;
    unsigned int y = 1;
    unsigned int compteur=0;

    for(auto &it : shop.get_contenu()){
        tab_vue_shop.push_back(new VueCarte(*(it.first),true));

        connect((tab_vue_shop)[compteur],SIGNAL(carteClicked(VueCarte*)),this,SLOT(batiment_clique(VueCarte*)));
        this->addWidget((tab_vue_shop)[compteur],x,y-1);
        if(it.second>1){
            // cas où on a plusieurs cartes identiques les unes sur les autres
            QLabel* nb_carte = new QLabel;
            nb_carte->setText(QString::number(it.second));
            //nb_carte->setAttribute(Qt::WA_TranslucentBackground);
            nb_carte->setStyleSheet("QLabel { color : white; background-color : black; }");
            nb_carte->setFixedSize(20,20);
            nb_carte->setAlignment(Qt::AlignTop | Qt::AlignCenter);
            this->addWidget(nb_carte,x,y-1);
            this->setAlignment(nb_carte,Qt::AlignTop | Qt::AlignRight);
        }
        if(y % largeur == 0){
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
    if (Partie::get_instance()->get_vue_partie()->get_vue_carte() != nullptr) {
        Partie::get_instance()->get_vue_partie()->get_vue_carte()->close();
    }
    QWidget* fenetre = new QWidget();
    Partie::get_instance()->get_vue_partie()->set_vue_carte(fenetre);
    // Création d'un label contenant l'image
    QLabel *label = new QLabel(fenetre);
    QPixmap pixmap(QString::fromStdString(vc->getCarte()->get_path_image()));
    bouton_acheter = new QPushButton(fenetre);
    bouton_acheter->setText(QString::fromStdString("Acheter le batiment"));
    Partie* partie_actuelle = Partie::get_instance();

    connect(bouton_acheter, SIGNAL(clicked()), this, SLOT(clicked_acheter_event()));

    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    // Affichage de la fenetre pop up
    fenetre->show();
}

void VueShop::update() {
    unsigned int x = 0;
    unsigned int y = 1;
    unsigned int compteur=0;

    for(auto &it : Partie::get_instance()->get_shop()->get_contenu()){
        tab_vue_shop.push_back(new VueCarte(*(it.first),true));

        connect((tab_vue_shop)[compteur],SIGNAL(carteClicked(VueCarte*)),this,SLOT(batiment_clique(VueCarte*)));
        this->addWidget((tab_vue_shop)[compteur],x,y-1);
        if(it.second>1){
            // cas où on a plusieurs cartes identiques les unes sur les autres
            QLabel* nb_carte = new QLabel;
            nb_carte->setText(QString::number(it.second));
            //nb_carte->setAttribute(Qt::WA_TranslucentBackground);
            nb_carte->setStyleSheet("QLabel { color : yellow; background-color : red; }");
            nb_carte->setFixedSize(20,20);
            nb_carte->setAlignment(Qt::AlignTop | Qt::AlignRight);
            this->addWidget(nb_carte,x,y-1);
            this->setAlignment(nb_carte,Qt::AlignTop | Qt::AlignRight);
        }
        if(y % largeur == 0){
            x ++;
            y = 1;
        }else{
            y++;
        }
        compteur++;
    }
}

void VueShop::clicked_acheter_event(VueCarte* vc){
    Partie* partie_actuelle = Partie::get_instance();
    partie_actuelle->acheter_carte_event(vc);
}