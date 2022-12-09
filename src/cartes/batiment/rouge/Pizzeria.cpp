#include "Pizzeria.h"

Pizzeria::Pizzeria() :
            Batiment("Pizzeria",
                     1 ,
                     "Recevez 1 piece du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Pizzeria.jpg",
                     Rouge,
                     list<unsigned int>{7},
                     "restaurant"){};

void Pizzeria::declencher_effet(unigned int possesseur) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de la pizzeria" << endl;
    //Trouver un joueur qui a cette carte
    //si il y en a un enlever une piece au joueur actuel et ajouter un au joueur qui en a une
}