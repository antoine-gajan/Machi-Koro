#include "SushiBar.h"

SushiBar::SushiBar() :
            Batiment("SushiBar",
                     4 ,
                     "Si vous avez le port, recevez 3 pieces du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Sushi-bar.jpg",
                     Rouge ,
                     list<unsigned int>{1},
                     "restaurant"){};

void SushiBar::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du Sushi Bar" << endl;
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever 2 piece au joueur actuel et ajouter 2 piece au joueur qui en a une
}