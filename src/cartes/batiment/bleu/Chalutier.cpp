#include "Chalutier.h"
#include "Partie.h"

Chalutier::Chalutier() :
        Batiment("Chalutier",
        5,
        "Le joueur dont c'est le tour lance deux des. Si vous avez le Port, recevez de la banque autant de pieces que le total des deux des",
        "../../assets/batiments/bleu/Chalutier.jpg",
        Bleu,
        list<unsigned int>{12,13,14},
        "Bateau"){}

///Constructeur de Chalutier

void Chalutier::declencher_effet(unsigned int possesseur, int bonus) const{

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);

    //on verifie si le joueur selectionne possede la carte Port
    if(joueur_actuel->possede_batiment("Port") != nullptr){
        cout << "Activation de l'effet de Chalutier" << endl;//on affiche seulement si le joueur possede le port
        unsigned int result_des;
        unsigned int argent;
        cout<<"Tirage des deux des"<<endl;
        result_des = rand() % 11 + 1;
        argent = joueur_actuel->get_argent();
        joueur_actuel->set_argent(argent+=result_des);
    }
}

