#include "Deluxe.h"

/// Import des Monuments
#include "Aeroport.h"
#include "CentreCommercial.h"
#include "Gare.h"
#include "ParcAttraction.h"
#include "Port.h"
#include "TourRadio.h"


/// Importation des batiments verts
#include "Boulangerie.h"
#include "EntrepriseDeDemenagement.h"
#include "EntrepriseDeTravauxPublics.h"
#include "Epicerie.h"
#include "FabriqueDeMeubles.h"
#include "HalleDeMarche.h"
#include "MarcheDeFruitsEtLegumes.h"
#include "MoonsterSoda.h"
#include "Superette.h"

/// Importation des batiments bleus
#include "Chalutier.h"
#include "ChampBle.h"
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

/// Importation des batiments violets
#include "CentreAffaires.h"
#include "CentreImpots.h"
#include "ChaineTelevision.h"
#include "MaisonEdition.h"
#include "Stade.h"


Deluxe::Deluxe(){
    /// Constructeur de Marina
    // Liste des monuments
    vector<Monument*> mon;
    mon.push_back(new Aeroport());
    mon.push_back(new CentreCommercial());
    mon.push_back(new Gare());
    mon.push_back(new ParcAttraction());
    mon.push_back(new Port());
    mon.push_back(new TourRadio());

    // Liste des batiments
    map<Batiment*, unsigned int> bat;

    // Batiments violets
    bat.insert(pair<Batiment*, unsigned int>(new CentreAffaires(), 2));
    bat.insert(pair<Batiment*, unsigned int>(new ChaineTelevision(), 2));
    bat.insert(pair<Batiment*, unsigned int>(new Stade(), 2));
    bat.insert(pair<Batiment*, unsigned int>(new CentreImpots(), 2));
    bat.insert(pair<Batiment*, unsigned int>(new MaisonEdition(), 2));

    // Batiments verts
    bat.insert(pair<Batiment*, unsigned int>(new Boulangerie(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new EntrepriseDeDemenagement(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new EntrepriseDeTravauxPublics(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Epicerie(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new FabriqueDeMeubles(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new HalleDeMarche(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new MarcheDeFruitsEtLegumes(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new MoonsterSoda(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Superette(), 5));

    // Batiments bleus
    bat.insert(pair<Batiment*, unsigned int>(new Chalutier(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new ChampBle(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Ferme(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Foret(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Mine(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Verger(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Vignoble(), 5));

    // Batiments rouges
    bat.insert(pair<Batiment*, unsigned int>(new Cafe(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new ClubPrive(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Pizzeria(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Restaurant5Etoiles(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new RestaurantFamilial(), 5));

    // Appel du constructeur
    EditionDeJeu("Deluxe",
                 2,
                 5,
                 5,
                 mon,
                 bat,
                 true
    );
}
