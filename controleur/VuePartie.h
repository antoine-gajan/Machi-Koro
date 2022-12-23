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
#include "Boulangerie.h"
#include "Aeroport.h"
#include "Epicerie.h"
#include "Cafe.h"
#include "Partie.h"
#include <QStackedWidget>

class VuePartie : public QWidget
{
    Q_OBJECT
public:

    explicit VuePartie(Partie *partie = nullptr, QWidget *parent = nullptr);
    const vector <VueJoueur*>& get_tab_vue_joueurs() const {return tab_vue_joueurs;};

private:
    Partie* partie;
    QStackedWidget *stack;
    unsigned int nb_joueurs;
    unsigned int joueur_affiche;
    vector<VueJoueur *> tab_vue_joueurs;
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
    QHBoxLayout *pioche;

    vector<Joueur*> tab_j;
    QWidget *parent;



public slots:
        // Slots qui gèrent les clics sur les vues joueurs
        virtual void carteClique(VueCarte* vc);
        void d_click();
        void g_click();
};

#endif //MACHI_KORO_VUEPARTIE_H
