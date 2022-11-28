cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(cartes)
include_directories(cartes/batiment)
include_directories(cartes/monument)
include_directories(Joueur)
include_directories(controleur)
include_directories(Joueur)

add_executable(src
    main.cpp

    controleur/EditionDeJeu.cpp
    controleur/EditionDeJeu.h
    controleur/Partie.cpp
    controleur/Partie.h
    controleur/Pioche.cpp
    controleur/Pioche.h
    controleur/Shop.cpp
    controleur/Shop.h
    controleur/utils.cpp
    controleur/utils.h

    cartes/Carte.cpp
    cartes/Carte.h

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
)