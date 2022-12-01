#include "RestaurantFamilial.h"

RestaurantFamilial::RestaurantFamilial() :
            Batiment("Restaurant",
                     3,
                     "Recevez 2 pieces du joueur qui a lance les des",
                     "../../assets/batiments/Rouge/Restaurant.jpg",
                     Rouge ,
                     list<unsigned int>{ 9,10 },
                     "restaurant") {};


void RestaurantFamilial::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"Activation de l'effet du restaurant";
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever 2 pièce au joueur actuel et ajouter 2 pièce au joueur qui en a une
}
