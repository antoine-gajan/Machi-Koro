#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H

#include <string>
#include <iostream>

using namespace std;

class Carte {
private:
    string nom;
    string description_effet;
    int prix;
    string path_image;

public:
    const static unsigned int prix_min;
    Carte(const string& name, const string& effect_description, int price, const string& path_picture);
    ~Carte() = default;
    string get_nom() const { return nom; }
    string get_description() const { return description_effet; }
    unsigned int get_prix() const { return prix; }
    string get_path_image() const { return path_image; }
};


#endif //MACHI_KORO_CARTE_H
