#include "Marina.h"

Marina::Marina() :
    EditionDeJeu("Marina",
                 2,
                 4,
                 6,
                 {Aeroport(), Port(), HotelDeVille()},
                 {4, 4, 4},
                 { MoonsterSoda(), Pizzeria(), SushiBar(), Chalutier(), ChampFleur(), BateauPeche(), Fleuriste(), HalleDeMarche(),
                   CentreImpots(), MaisonEdition()},
                 {},
                 false
            )
{}
