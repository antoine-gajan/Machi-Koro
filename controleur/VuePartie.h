#ifndef MACHI_KORO_VUEPARTIE_H
#define MACHI_KORO_VUEPARTIE_H
#include <QApplication>
#include <QtGui/QScreen>
#include <QScrollArea>
#include <QStyleFactory>
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
    void lancer_de_1_display();
    void lancer_de_2_display();
    void update_des();
    void update_nom_joueur();
    void update_pasta (const string& pasta);
    void clear_pasta(bool etat_clear);

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
    QLabel* image_entete;
    QPushButton *bouton_lancer_de_1;
    QPushButton *bouton_lancer_de_2;

    //partitionnement de la page
    QVBoxLayout *structure;
    QHBoxLayout *layout;
    QHBoxLayout *entete;
    QVBoxLayout *entete_gauche;

    QVBoxLayout *display_des;
    QHBoxLayout* layout_de_1;
    QHBoxLayout* layout_de_2;
    QHBoxLayout *body;
    VueJoueur* vue_joueur;
    QWidget *parent_fenetre;
    QWidget *fenetre_carte;

    /// Milieu de la page
    //Pioche à gauche
    QVBoxLayout *pioche;
    QVBoxLayout* view_pioche;

    //Shop au centre
    QGridLayout* view_shop;
    QScrollArea* scroll_shop;
    QWidget* widget_shop;

    //Pasta à droite
    QWidget *scroll_widget_pasta;
    QScrollArea *scroll_pasta;
    QVBoxLayout *stacked_pasta;
    QLabel * pasta_label;
    QWidget *widget_pasta;
    QVBoxLayout *view_widget_pasta;
    vector<QLabel*> pasta;



public slots:
    // Slots qui gèrent les clics sur les vues joueurs
        //virtual void carteClique(VueCarte* vc);
        void d_click();
        void g_click();

        void clicked_event_de_1();
        void clicked_event_de_2();
};

#endif //MACHI_KORO_VUEPARTIE_H
