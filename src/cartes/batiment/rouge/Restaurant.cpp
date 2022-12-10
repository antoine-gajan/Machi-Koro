#include "Restaurant.h"

Restaurant::Restaurant() :
            Batiment("Restaurant",
                     3,
                     "Recevez 2 pieces du joueur qui a lance les des",
                     "../../assets/batiments/Rouge/Restaurant.jpg",
                     Rouge ,
                     list<unsigned int>{ 9,10 },
                     "restaurant") {};


void Restaurant::declencher_effet(unsigned int possesseur) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du restaurant" << endl;
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever 2 piece au joueur actuel et ajouter 2 piece au joueur qui en a une
}
