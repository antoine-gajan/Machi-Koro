#include "Marina.h"
#include "Batiment.h"
#include "Monument.h"
#include "MoonsterSoda.h"
#include "Aeroport.h"
#include "Pizzeria.h"
#include "Port.h"
#include "HotelDeVille.h"
#include "SushiBar.h"
#include "Chalutier.h"
#include "ChampFleur.h"
#include "BateauPeche.h"
#include "Fleuriste.h"
#include "HalleDeMarche.h"
#include "CentreImpots.h"
#include "MaisonEdition.h"

Marina::Marina(){
    /// Constructeur de Marina
    // Liste des monuments
    vector<Monument*> mon;
    mon.push_back(new Aeroport());
    mon.push_back(new Port());
    mon.push_back(new HotelDeVille());

    // Liste des batiments
    map<Batiment*, unsigned int> bat;
    bat.insert(pair<Batiment*, unsigned int>(new MoonsterSoda(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new Pizzeria(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new SushiBar(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new Chalutier(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new ChampFleur(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new BateauPeche(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new Fleuriste(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new HalleDeMarche(), 6));
    bat.insert(pair<Batiment*, unsigned int>(new CentreImpots(), 4));
    bat.insert(pair<Batiment*, unsigned int>(new MaisonEdition(), 4));

    // Appel du constructeur
    EditionDeJeu("Marina",
                 2,
                 4,
                 6,
                mon,
                 bat,
                 false
    );
}
