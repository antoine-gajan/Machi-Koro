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
    explicit VueJoueur(Joueur* joueur, QWidget *parent = nullptr);
private:
    QLabel* nom_joueur; // texte "Score"
    QLCDNumber* argent; // affichage de l'argent du joueur
    QHBoxLayout* layoutInformations;
    QGridLayout* layoutBatiments; // grille des batiments du joueur
    QGridLayout* layoutMonuments; // grille des monuments du joueur
    vector<VueCarte*> vuecartes; // adresses des objets VueCarte
private slots:
    // slots qui gère les clics sur les cartes
    //void carteClique(VueCarte* vc);
};


#endif //MACHI_KORO_VUEJOUEUR_H
