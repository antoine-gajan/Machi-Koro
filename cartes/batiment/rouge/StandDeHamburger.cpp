#include "StandDeHamburger.h"

StandDeHamburger::StandDeHamburger() :
            Batiment("StandDeHamburger",
                     1 ,
                     "Recevez 1 piece du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Monster-burger.jpg",
                     Rouge,
                     list<unsigned int>{8},
                     "restaurant"){};

void StandDeHamburger::declencher_effet(unsigned int possesseur, int bonus) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du stand de hamburger" << endl;
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever 1 piece au joueur actuel et ajouter 1 piece au joueur qui en a une
}