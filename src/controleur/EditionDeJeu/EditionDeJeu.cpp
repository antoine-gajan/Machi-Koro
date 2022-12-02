#include "EditionDeJeu.h"
/// Importation des classes monuments
#include "Aeroport.h"
#include "CentreCommercial.h"
#include "FabriqueDuPereNoel.h"
#include "Gare.h"
#include "HotelDeVille.h"
#include "ParcAttraction.h"
#include "Port.h"
#include "TourRadio.h"

/// Importation des batiments verts
#include "BanqueDeMinivilles.h"
#include "Boulangerie.h"
#include "EntrepriseDeDemenagement.h"
#include "EntrepriseDeTravauxPublics.h"
#include "Epicerie.h"
#include "FabriqueDeMeubles.h"
#include "Fleuriste.h"
#include "Fromagerie.h"
#include "HalleDeMarche.h"
#include "MarcheDeFruitsEtLegumes.h"
#include "MoonsterSoda.h"
#include "Superette.h"

/// Importation des batiments bleus
#include "Chalutier.h"
#include "ChampBle.h"
#include "ChampFleur.h"
#include "ChampMais.h"
#include "Ferme.h"
#include "Foret.h"
#include "Mine.h"
#include "Verger.h"
#include "Vignoble.h"

/// Importation des batiments rouges
#include "Cafe.h"
#include "ClubPrive.h"
#include "Pizzeria.h"
#include "Restaurant5Etoiles.h"
#include "RestaurantFamilial.h"
#include "StandDeHamburger.h"
#include "SushiBar.h"

/// Importation des batiments violets
#include "Arboretum.h"
#include "CentreAffaires.h"
#include "CentreImpots.h"
#include "ChaineTelevision.h"
#include "EntrepriseRenovation.h"
#include "MaisonEdition.h"
#include "Stade.h"
#include "Startup.h"


EditionDeJeu::EditionDeJeu(const string& nom_edition) {
    /// Constructeur de EditionDeJeu

    //Gestion des erreurs
    if (nom_edition.empty()){
        throw invalid_argument("Le nom de l'édition ne peut être vide.");
    }

    if (nom_edition == "Deluxe") {
        nom = "Deluxe";
        est_edition = true;
        nb_joueurs_max = 5;
        nb_joueurs_min = 2;
        nb_monuments_win = 5;

        // Liste des monuments spécifiques à Deluxe
        mon = vector<Monument>();
    }
}
