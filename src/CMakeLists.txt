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
)