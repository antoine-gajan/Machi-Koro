#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H

#include <string>
#include <iostream>

using namespace std;

class Carte {
private:
    string nom;
    string description_effet;
    unsigned int prix;
    string path_image;

public:
    Carte(const string& name, const string& effect_description, unsigned int price, const string& path_picture);
    ~Carte() = default;
    const string& get_nom() const { return nom; }
    const string& get_description() const { return description_effet; }
    unsigned int get_prix() const { return prix; }
    const string& get_path_image() const { return path_image; }

    virtual string get_type() const = 0;
};


#endif //MACHI_KORO_CARTE_H
