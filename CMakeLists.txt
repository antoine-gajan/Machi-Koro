cmake_minimum_required(VERSION 3.23)
project(Machi_Koro)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/cartes)
include_directories(src/cartes/batiment)
include_directories(src/cartes/monument)
include_directories(src/Joueur)

add_executable(Machi_Koro
        src/cartes/batiment/Batiment.cpp
        src/cartes/batiment/Batiment.h
        src/cartes/monument/Gare.cpp
        src/cartes/monument/Gare.h
        src/cartes/monument/Monument.cpp
        src/cartes/monument/Monument.h
        src/cartes/Carte.cpp
        src/cartes/Carte.h
        src/Joueur/Joueur.cpp
        src/Joueur/Joueur.h
        src/main.cpp
        template/template.cpp
        template/template.h src/cartes/batiment/violet/CentreAffaires.cpp src/cartes/batiment/violet/CentreAffaires.h src/cartes/batiment/violet/ChaineTelevision.cpp src/cartes/batiment/violet/ChaineTelevision.h src/cartes/batiment/violet/Stade.cpp src/cartes/batiment/violet/Stade.h src/cartes/batiment/bleu/ChampsBle.cpp src/cartes/batiment/bleu/ChampsBle.h src/cartes/batiment/rouge/Cafe.cpp src/cartes/batiment/rouge/Cafe.h src/cartes/batiment/vert/Boulangerie.cpp src/cartes/batiment/vert/Boulangerie.h src/cartes/monument/Port.cpp src/cartes/monument/Port.h src/cartes/monument/Centre_commercial.cpp src/cartes/monument/Centre_commercial.h src/cartes/monument/Parc_attraction.cpp src/cartes/monument/Parc_attraction.h src/cartes/monument/Tour_radio.cpp src/cartes/monument/Tour_radio.h src/cartes/monument/Aeroport.cpp src/cartes/monument/Aeroport.h)
