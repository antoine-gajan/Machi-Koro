#include "Pioche.h"

Pioche::Pioche(const vector<Batiment*>& batiments) {
    /// Constructeur de la classe Pioche

    for (auto batiment : batiments) {
        contenu.push(batiment);
    }
}

Batiment* Pioche::get_carte() {
    /// Fonction qui retourne la premiere carte de la pioche
    // Si la pioche est non vide
    if (!contenu.empty()){
        // Recupere la tête et on la renvoie
        Batiment *bat = contenu.top();
        contenu.pop();
        return bat;
    }
    // Sinon, on renvoie nullptr (erreur)
    else
    {
        cout << "La pioche est vide." <<endl;
        return nullptr;
    }
}

