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
    void update(Joueur* j, VuePartie* vj);
private:
    Partie* partie;
    QStackedWidget *stack;
    unsigned int nb_joueurs;
    unsigned int joueur_affiche;
    vector<VueJoueur *> tab_vue_joueurs;
    QHBoxLayout *layout;
    QWidget *parent;
    vector<Joueur*> tab_j;



public slots:
        // Slots qui gèrent les clics sur les vues joueurs
        void d_click();
        void g_click();
};

#endif //MACHI_KORO_VUEPARTIE_H
