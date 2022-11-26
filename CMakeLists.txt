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
        src/controleur/utils.cpp src/controleur/utils.h
        template/template.h src/cartes/batiment/violet/CentreAffaires.cpp src/cartes/batiment/violet/CentreAffaires.h src/cartes/batiment/violet/ChaineTelevision.cpp src/cartes/batiment/violet/ChaineTelevision.h src/cartes/batiment/violet/Stade.cpp src/cartes/batiment/violet/Stade.h src/cartes/batiment/bleu/ChampBle.cpp src/cartes/batiment/bleu/ChampBle.h src/cartes/batiment/rouge/Cafe.cpp src/cartes/batiment/rouge/Cafe.h src/cartes/batiment/vert/Boulangerie.cpp src/cartes/batiment/vert/Boulangerie.h src/cartes/monument/Port.cpp src/cartes/monument/Port.h src/cartes/monument/Centre_commercial.cpp src/cartes/monument/Centre_commercial.h src/cartes/monument/Parc_attraction.cpp src/cartes/monument/Parc_attraction.h src/cartes/monument/Tour_radio.cpp src/cartes/monument/Tour_radio.h src/cartes/monument/Aeroport.cpp src/cartes/monument/Aeroport.h src/controleur/Pioche.cpp src/controleur/Pioche.h src/controleur/Partie.cpp src/controleur/Partie.h src/controleur/EditionDeJeu.cpp src/controleur/EditionDeJeu.h
        src/cartes/batiment/vert/Boulangerie.cpp src/cartes/batiment/vert/Boulangerie.h src/cartes/batiment/vert/EntrepriseDeDemenagement.cpp src/cartes/batiment/vert/EntrepriseDeDemenagement.cpp src/cartes/batiment/vert/EntrepriseDeTravauxPublics.cpp src/cartes/batiment/vert/EntrepriseDeTravauxPublics.h src/cartes/batiment/vert/Epicerie.cpp src/cartes/batiment/vert/Epicerie.h src/cartes/batiment/vert/FabriqueDeMeubles.cpp src/cartes/batiment/vert/FabriqueDeMeubles.h src/cartes/batiment/vert/Fleuriste.cpp src/cartes/batiment/vert/Fleuriste.h src/cartes/batiment/vert/Fromagerie.cpp src/cartes/batiment/vert/Fromagerie.h src/cartes/batiment/vert/HalleDeMarche.cpp src/cartes/batiment/vert/HalleDeMarche.h src/cartes/batiment/vert/MarcheDeFruitsEtLegumes.cpp src/cartes/batiment/vert/MarcheDeFruitsEtLegumes.h src/cartes/batiment/vert/MoonsterSoda.cpp src/cartes/batiment/vert/MoonsterSoda.h src/cartes/batiment/vert/Superette.cpp src/cartes/batiment/vert/Superette.h)
