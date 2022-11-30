#include "SushiBar.h"

SushiBar::SushiBar() :
            Batiment("Sushi bar",
                     4 ,
                     "Si vous avez le port, recevez 3 pieces du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Sushi-bar.jpg",
                     Rouge ,
                     list<unsigned int>{1},
                     "restaurant"){};

void SushiBar::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"Activation de l'effet du Sushi Bar";
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever 2 pièce au joueur actuel et ajouter 2 pièce au joueur qui en a une
}