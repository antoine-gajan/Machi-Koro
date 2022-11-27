#include "utils.h"


unsigned int count_type(Joueur *joueur, const string& type) {
    unsigned int count = 0;

    // pour chaque couleur de la liste de batissements du joueur
    map<string, map<Batiment*, unsigned int>>::iterator it;
    for (it=joueur->get_liste_batiment().begin(); it!=joueur->get_liste_batiment().end(); ++it) {

        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        map<Batiment*, unsigned int>::iterator it2;
        for (it2=it->second.begin(); it2!=it->second.end(); ++it2) {
            if (it2->first->get_type() == type) {
                count += it2->second;
            }
        }
    }

    return count;
}

map<Batiment*, unsigned int> get_liste_bat_non_special(Joueur* j){
    map<Batiment* ,unsigned int> liste;
    for (auto couleur : j->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_type() != "spécial")
            {
                liste.insert(pair<Batiment*, unsigned int>(bat.first, bat.second));
            }
        }
    }
    return liste;
}

void swap_bat_players(Joueur *j1, Joueur *j2, const string& bat1, const string& bat2){
    ///Fonction qui échange les batiments de 2 joueurs
    //Trouver le batiment dans la liste du joueur 1
    pair<Batiment*, unsigned int> batiment1;
    for (auto couleur : j1->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_nom() == bat1)
            {
                batiment1 = bat;
            }
        }
    }

    //Trouver le batiment dans la liste du joueur 2
    pair<Batiment*, unsigned int> batiment2;
    for (auto couleur : j1->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_nom() == bat2)
            {
                batiment2 = bat;
            }
        }
    }
    // On retire le bat à donner du joueur actuel
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment1.second == 1)
    {
        j1->get_liste_batiment().find(batiment1.first->get_couleur()).erase(batiment1.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        j1->get_liste_batiment().find(batiment1.first)->second--;
    }

    // Ajout du batiment à donner au joueur de l'échange
    auto element = j2->get_liste_batiment().find(bat2.first);
    if (element != j2->get_liste_batiment().end()){
        element->second++;
    }
    else{
        joueur_echange->get_liste_batiment().insert(pair<Batiment*, unsigned int>(batiment_a_donner.first, 1));
    }

    // On retire le bat à recevoir du joueur échange
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment_a_recevoir.second == 1)
    {
        joueur_echange->get_liste_batiment().erase(batiment_a_recevoir.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        joueur_echange->get_liste_batiment().find(batiment_a_recevoir.first)->second--;
    }

    // Ajout du batiment à recevoir au joueur actuel
    auto element2 = j_actuel->get_liste_batiment().find(batiment_a_recevoir.first);
    // S'il a déjà un exemplaire de ce bâtiment, on incrémente sa quantité
    if (element2 != j_actuel->get_liste_batiment().end()){
        element2->second++;
    }
        // Sinon, on ajoute le batiment à sa liste
    else{
        j_actuel->get_liste_batiment().insert(pair<Batiment*, unsigned int>(batiment_a_recevoir.first, 1));
    }
}