#ifndef MACHI_KORO_VUEPARTIE_H
#define MACHI_KORO_VUEPARTIE_H

#include <QWidget>
#include "VueCarte.h"
#include "VueJoueur.h"
#include "Joueur.h"
#include "VueShop.h"
#include "VuePioche.h"
#include "VueInfo.h"
#include <QScrollArea>
#include <QStyleFactory>
#include <QFormLayout>


class VuePartie : public QWidget
{
    Q_OBJECT
public:

    explicit VuePartie(QWidget *parent = nullptr);

    /// Update de la vue
    void update_vue_joueur();
    void set_bouton_rien_faire(bool b) {bouton_rien_faire->setEnabled(b);}
    void update_des();

    /// Getters
    unsigned int get_nb_joueurs() const {return nb_joueurs;}
    unsigned int get_joueur_affiche() const {return joueur_affiche;}
    //Partie* get_partie_actuelle() const{return partie_actuelle;}
    QWidget* get_vue_carte() const {return fenetre_carte;}
    void set_vue_carte(QWidget* vue_carte) {fenetre_carte = vue_carte;}
    void lancer_de_1_display();
    void lancer_de_2_display();
    void update_nom_joueur();

    VueJoueur* get_vue_joueur() const {return vue_joueur;}
    VueShop* get_vue_shop() const {return view_shop;}
    VuePioche* get_vue_pioche() const {return view_pioche;}
    VueInfo* get_vue_infos() const {return infos;}
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
    VueShop* shop;
    QLabel* image_entete;
    QPushButton *bouton_lancer_de_1;
    QPushButton *bouton_lancer_de_2;
    //partitionnement de la page
    QVBoxLayout *structure;

    QHBoxLayout *layout;
    QHBoxLayout *entete;
    QVBoxLayout *entete_gauche;
    /// Au de la page
    QVBoxLayout *display_des;

    QHBoxLayout* layout_de_1;
    QHBoxLayout* layout_de_2;
    QHBoxLayout *body;
    VueJoueur* vue_joueur;
    QWidget *parent_fenetre;
    QWidget *fenetre_carte;
    QPushButton* bouton_rien_faire;
    QPushButton* bouton_tour_suivant;
    /// Milieu de la page
    //Pioche à gauche
    QVBoxLayout *pioche;

    QWidget *fenetre_pioche;
    VuePioche* view_pioche;
    //Shop au centre
    VueShop* view_shop;

    QScrollArea* scroll_shop;
    QWidget* widget_shop;
    //Infos à droite
    VueInfo *infos;

    QWidget* widget_infos;
public slots:

    // Slots qui gèrent les clics sur les vues joueurs
        //virtual void carteClique(VueCarte* vc);

    void d_click();
    void g_click();

    void clicked_event_de_1();

    void clicked_event_de_2();
    void tour_suivant();
};

#endif //MACHI_KORO_VUEPARTIE_H
