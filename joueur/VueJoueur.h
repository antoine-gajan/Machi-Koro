#ifndef MACHI_KORO_VUEJOUEUR_H
#define MACHI_KORO_VUEJOUEUR_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include "VueCarte.h"
#include "Joueur.h"

class VueJoueur : public QWidget
{
Q_OBJECT
public:
    explicit VueJoueur(Joueur* j,bool e_j_a,  QWidget *parent = nullptr);
    void replace_argent(int i) {argent->display(i);};
    QLCDNumber* get_widget_argent() const{return argent;};
    void add_batiment(VueCarte* vc){return vue_batiments->push_back(vc);}
    void add_batiment_ferme(VueCarte* vc){return vue_batiments_ferme->push_back(vc);}
    void update_monu(VueCarte* vc){}
    const Joueur& get_joueur() const {return *joueur;}
    const vector<VueCarte*>& get_vue_batiments() const {return *vue_batiments;}
    const vector<VueCarte*>& get_vue_batiments_ferme() const {return *vue_batiments_ferme;}
    const vector<VueCarte*>& get_vue_monuments() const {return *vue_monuments;}
    bool get_est_joueur_actuel() const{return est_joueur_actuel;}
    void update_vue();
private:
    bool est_joueur_actuel;
    QLabel* text_bat;
    QLabel* nom_joueur; // texte avec le nom du joueur
    QLCDNumber* argent; // affichage de l'argent du joueur
    QHBoxLayout* layout_informations;
    QGridLayout* layout_batiments; // grille des batiments du joueur
    QGridLayout* layout_monuments; // grille des monuments du joueur
    QGridLayout* layout_batiments_ferme; // grille des batiments ferme du joueu// r
    vector<VueCarte*>* vue_batiments; // adresses des batiments VueCarte
    vector<VueCarte*>* vue_batiments_ferme; // adresses des batiments fermés VueCarte
    vector<VueCarte*>* vue_monuments; // adresses des monuments VueCarte
    QWidget* fenetre_bat_fermes; // Fenetre avec les batiments fermés
    QHBoxLayout* layout_haut_gauche;
    QVBoxLayout* layout_informations_gauche;
    QPushButton *bat_ferme;
    Joueur *joueur;
    QWidget *parent;

public slots:
    // slots qui gère les clics sur les cartes
    virtual void batimentClique(VueCarte* vc);
    void affichage_bat_ferme();
    void monumentClique(VueCarte* vc);
};


#endif //MACHI_KORO_VUEJOUEUR_H
