#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H

#include <string>
#include <iostream>
class Carte {
protected:
    std::string nom;
    std::string description_effet;
    unsigned int prix;
    std::string path_image;

public:
    Carte(const std::string& name, const std::string& effect_description, unsigned int price, const std::string& path_picture);
    virtual ~Carte() = default;
    const std::string& get_nom() const { return nom; }
    const std::string& get_description() const { return description_effet; }
    unsigned int get_prix() const { return prix; }
    const std::string& get_path_image() const { return path_image; }


    virtual std::string get_type() const = 0;

    virtual void declencher_effet() const = 0;
};


#endif //MACHI_KORO_CARTE_H
