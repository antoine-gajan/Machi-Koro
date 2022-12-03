#include "Pioche.h"
#include "Batiment.h"

Pioche::Pioche(const vector<Batiment*>& batiments) {
    /// Constructeur de la classe Pioche

    for (size_t i = 0; i < batiments.size(); i++) {
        contenu.push(batiments[i]);
    }
}

Batiment* Pioche::getCarte() {
    /// Fonction qui retourne la première carte de la pioche
    // Si la pioche est non vide
    if (contenu.size() > 0){
        // Récupère la tête et on la renvoie
        Batiment * bat = contenu.top();
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
