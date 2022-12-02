#include "EditionDeJeu.h"


EditionDeJeu::EditionDeJeu(const string& nom_edition) {
    /// Constructeur de EditionDeJeu

    //Gestion des erreurs
    if (nom_edition.empty()){
        throw invalid_argument("Le nom de l'édition ne peut être vide.");
    }

    if (nom_edition == "Deluxe") {
        /// Constructeur de Deluxe
        nom = "Deluxe";
        est_edition = true;
        nb_joueurs_max = 5;
        nb_joueurs_min = 2;
        nb_monuments_win = 5;

        // Liste des monuments spécifiques à Deluxe
        monument.push_back(new Aeroport());
        monument.push_back(new CentreCommercial());
        monument.push_back(new Gare());
        monument.push_back(new ParcAttraction());
        monument.push_back(new Port());
        monument.push_back(new TourRadio());

        // Liste des batiments spécifiques à Deluxe
        // Batiments violets
        batiment.insert(pair<Batiment*, unsigned int>(new CentreAffaires(), 2));
        batiment.insert(pair<Batiment*, unsigned int>(new ChaineTelevision(), 2));
        batiment.insert(pair<Batiment*, unsigned int>(new Stade(), 2));
        batiment.insert(pair<Batiment*, unsigned int>(new CentreImpots(), 2));
        batiment.insert(pair<Batiment*, unsigned int>(new MaisonEdition(), 2));

        // Batiments verts
        batiment.insert(pair<Batiment*, unsigned int>(new Boulangerie(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new EntrepriseDeDemenagement(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new EntrepriseDeTravauxPublics(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Epicerie(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new FabriqueDeMeubles(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new HalleDeMarche(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new MarcheDeFruitsEtLegumes(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new MoonsterSoda(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Superette(), 5));

        // Batiments bleus
        batiment.insert(pair<Batiment*, unsigned int>(new Chalutier(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new ChampBle(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Ferme(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Foret(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Mine(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Verger(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Vignoble(), 5));

        // Batiments rouges
        batiment.insert(pair<Batiment*, unsigned int>(new Cafe(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new ClubPrive(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Pizzeria(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new Restaurant5Etoiles(), 5));
        batiment.insert(pair<Batiment*, unsigned int>(new RestaurantFamilial(), 5));
    }
}