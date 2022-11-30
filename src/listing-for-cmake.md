# Stockage dans ce fichier des liens pour le fichier CMakeLists.txt et les imports


## CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(cartes)
include_directories(cartes/batiment)
include_directories(cartes/batiment/vert)
include_directories(cartes/monument)
include_directories(Joueur)
include_directories(controleur)
include_directories(Joueur)

add_executable(src
        main.cpp

        Joueur/Joueur.cpp
        Joueur/Joueur.h

        cartes/Carte.cpp
        cartes/Carte.h

        cartes/batiment/Batiment.cpp
        cartes/batiment/Batiment.h

        cartes/monument/Monument.cpp
        cartes/monument/Monument.h
        
        cartes/monument/Aeroport.cpp
        cartes/monument/Aeroport.h
        cartes/monument/CentreCommercial.cpp
        cartes/monument/CentreCommercial.h
        cartes/monument/Gare.cpp
        cartes/monument/Gare.h
        cartes/monument/ParcAttraction.cpp
        cartes/monument/ParcAttraction.h
        cartes/monument/Port.cpp
        cartes/monument/Port.h
        cartes/monument/TourRadio.cpp
        cartes/monument/TourRadio.h
        cartes/monument/FabriqueDuPereNoel.cpp
        cartes/monument/FabriqueDuPereNoel.h
        cartes/monument/HotelDeVille.cpp
        cartes/monument/HotelDeVille.h

        cartes/batiment/vert/BanqueDeMinivilles.cpp
        cartes/batiment/vert/BanqueDeMinivilles.h
        cartes/batiment/vert/Boulangerie.cpp
        cartes/batiment/vert/Boulangerie.h
        cartes/batiment/vert/EntrepriseDeDemenagement.cpp
        cartes/batiment/vert/EntrepriseDeDemenagement.h
        cartes/batiment/vert/EntrepriseDeTravauxPublics.cpp
        cartes/batiment/vert/EntrepriseDeTravauxPublics.h
        cartes/batiment/vert/Epicerie.h
        cartes/batiment/vert/Epicerie.cpp
        cartes/batiment/vert/FabriqueDeMeubles.h
        cartes/batiment/vert/FabriqueDeMeubles.cpp
        cartes/batiment/vert/Fleuriste.h
        cartes/batiment/vert/Fleuriste.cpp
        cartes/batiment/vert/Fromagerie.h
        cartes/batiment/vert/Fromagerie.cpp
        cartes/batiment/vert/HalleDeMarche.cpp
        cartes/batiment/vert/HalleDeMarche.h
        cartes/batiment/vert/MarcheDeFruitsEtLegumes.h
        cartes/batiment/vert/MarcheDeFruitsEtLegumes.cpp
        cartes/batiment/vert/MoonsterSoda.h
        cartes/batiment/vert/MoonsterSoda.cpp
        cartes/batiment/vert/Superette.h
        cartes/batiment/vert/Superette.cpp
)
```

## Imports
```cpp
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

/// Importation des batiments rouges

/// Importation des batiments violets

/// Importation des controleurs

/// Importation des joueurs
)
```