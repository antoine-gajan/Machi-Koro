#include "Deluxe.h"

/// Import des Monuments
#include "Aeroport.h"
#include "Port.h"

/// Importation des batiments verts
#include "EntrepriseDeDemenagement.h"
#include "EntrepriseDeTravauxPublics.h"
#include "Epicerie.h"
#include "HalleDeMarche.h"
#include "MoonsterSoda.h"

/// Importation des batiments bleus
#include "Chalutier.h"
#include "Vignoble.h"

/// Importation des batiments rouges
#include "Cafe.h"
#include "ClubPrive.h"
#include "Pizzeria.h"
#include "Restaurant5Etoiles.h"

/// Importation des batiments violets
#include "CentreImpots.h"
#include "MaisonEdition.h"


Deluxe::Deluxe(){
    /// Constructeur de Deluxe
    // Liste des monuments spécifiques à Deluxe
    vector<Monument*> mon;
    mon.push_back(new Aeroport());
    mon.push_back(new Port());

    // Liste des batiments
    map<Batiment*, unsigned int> bat;

    // Batiments violets
    bat.insert(pair<Batiment*, unsigned int>(new CentreImpots(), 2));
    bat.insert(pair<Batiment*, unsigned int>(new MaisonEdition(), 2));

    // Batiments verts
    bat.insert(pair<Batiment*, unsigned int>(new EntrepriseDeDemenagement(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new EntrepriseDeTravauxPublics(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Epicerie(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new HalleDeMarche(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new MoonsterSoda(), 5));

    // Batiments bleus
    bat.insert(pair<Batiment*, unsigned int>(new Chalutier(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Vignoble(), 5));

    // Batiments rouges
    bat.insert(pair<Batiment*, unsigned int>(new ClubPrive(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Pizzeria(), 5));
    bat.insert(pair<Batiment*, unsigned int>(new Restaurant5Etoiles(), 5));

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
