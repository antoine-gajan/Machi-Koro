#include "ClubPrive.h"

ClubPrive::ClubPrive() :
            Batiment("ClubPrive",
                     4 ,
                     "Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois monuments construits.",
                     "../../assets/batiments/Rouge/Club-prive.jpg",
                     Rouge ,
                     list<unsigned int>{12,13,14},
                     "restaurant"){};

void ClubPrive::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du club prive" << endl;
    //Trouver un joueur qui a cette carte
    // verifier si le joueur actuel à au moins 3 monuments
    //si il y en a un enlever toutes les pièces(get_argent()) au joueur actuel et ajouter toutes les pièces au joueur qui en a une
}