#include "Cafe.h"

Cafe::Cafe() :
            Batiment("Cafe",
                     2,
                     "Recevez 1 piece du joueur qui a lance les des",
                     "../../assets/batiments/Rouge/Cafe.jpg",
                     Rouge ,
                     list<unsigned int>{3},
                     "restaurant") {};

void Cafe::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"Activation de l'effet du cafe";
}



