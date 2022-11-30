cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(cartes)
include_directories(cartes/batiment)
include_directories(cartes/batiment/violet)
include_directories(cartes/monument)
include_directories(Joueur)
include_directories(controleur)
include_directories(Joueur)

add_executable(src
        main.cpp
        cartes/Carte.cpp
        cartes/Carte.h

        cartes/batiment/batiment.cpp
        cartes/batiment/batiment.h

        cartes/batiment/violet/CentreAffaires.cpp
        cartes/batiment/violet/CentreAffaires.h
        cartes/batiment/violet/CentreImpots.cpp
        cartes/batiment/violet/CentreImpots.h
        cartes/batiment/violet/ChaineTelevision.cpp
        cartes/batiment/violet/ChaineTelevision.h
        cartes/batiment/violet/MaisonEdition.cpp
        cartes/batiment/violet/MaisonEdition.h
        cartes/batiment/violet/Stade.cpp
        cartes/batiment/violet/Stade.h
)