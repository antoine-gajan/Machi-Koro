#include "Restaurant5Etoiles.h"

Restaurant5Etoiles::Restaurant5Etoiles() :
            Batiment("Restaurant 5 etoiles",
                     3 ,
                     "Recevez 5 pieces du joueur qui a lance les des si celui-ci possede au moins deux monuments construits.",
                     "../../assets/batiments/Rouge/Restaurant-5-etoiles.jpg",
                     Rouge,
                     list<unsigned int>{5},
                     "restaurant"){};


void Restaurant5Etoiles::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"Activation de l'effet du restaurant 5 etoiles";
    //Trouver un joueur qui a cette carte
    // verifier si le joueur actuel à au moins 2 monuments
    //si il y en a un enlever 5 pièce au joueur actuel et ajouter 5 pièce au joueur qui en a une
}