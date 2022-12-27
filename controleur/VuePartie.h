#ifndef MACHI_KORO_VUEPARTIE_H
#define MACHI_KORO_VUEPARTIE_H
#include <QApplication>
#include <QtGui/QScreen>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>
#include "VueCarte.h"
#include "VueJoueur.h"
#include "Joueur.h"
#include "VueShop.h"
#include "VuePioche.h"
#include <QStackedWidget>

class VuePartie : public QWidget
{
    Q_OBJECT
public:

    explicit VuePartie(QWidget *parent = nullptr);
    void update_vue_joueur();
    unsigned int get_nb_joueurs() const {return nb_joueurs;}
    unsigned int get_joueur_affiche() const {return joueur_affiche;}
    //Partie* get_partie_actuelle() const{return partie_actuelle;}
    QWidget* get_vue_carte() const {return fenetre_carte;}
    void set_vue_carte(QWidget* vue_carte) {fenetre_carte = vue_carte;}


private:
    //Partie* partie_actuelle;
    unsigned int nb_joueurs;
    unsigned int joueur_affiche;
    vector<VueCarte *> tab_vue_shop;

    //Labels sur la page
    QLabel* label_edj;
    QLabel* label_joueur_actuel;
    QLabel* label_de1;
    QLabel* label_de2;
    QLabel* pioche_exception;
    QGridLayout* shop;

    //partitionnement de la page
    QVBoxLayout *structure;
    QHBoxLayout *layout;
    QHBoxLayout *entete;
    QVBoxLayout *display_des;
    QHBoxLayout *body;
    QVBoxLayout *pioche;
    VueJoueur* vue_joueur;
    QGridLayout* view_shop;
    QVBoxLayout* view_pioche;
    QWidget *parent_fenetre;
    QWidget *fenetre_carte;



public slots:
        // Slots qui gèrent les clics sur les vues joueurs
        //virtual void carteClique(VueCarte* vc);
        void d_click();
        void g_click();
};

#endif //MACHI_KORO_VUEPARTIE_H
