cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(cartes)
include_directories(cartes/batiment)
include_directories(cartes/batiment/violet)
add_executable(src
        main.cpp

        cartes/Carte.cpp
        cartes/Carte.h

        cartes/batiment/Batiment.cpp
        cartes/batiment/Batiment.h


        cartes/batiment/violet/Arboretum.cpp
        cartes/batiment/violet/Arboretum.h
        cartes/batiment/violet/CentreAffaires.cpp
        cartes/batiment/violet/CentreAffaires.h
        cartes/batiment/violet/CentreImpots.cpp
        cartes/batiment/violet/CentreImpots.h
        cartes/batiment/violet/ChaineTelevision.cpp
        cartes/batiment/violet/ChaineTelevision.h
        cartes/batiment/violet/EntrepriseRenovation.cpp
        cartes/batiment/violet/EntrepriseRenovation.h
        cartes/batiment/violet/MaisonEdition.cpp
        cartes/batiment/violet/MaisonEdition.h
        cartes/batiment/violet/Stade.cpp
        cartes/batiment/violet/Stade.h
        cartes/batiment/violet/Startup.cpp
        cartes/batiment/violet/Startup.h
)