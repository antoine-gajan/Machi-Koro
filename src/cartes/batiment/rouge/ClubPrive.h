#ifndef CLUB_PRIVE_H
#define CLUB_PRIVE_H

#include "Batiment.h"

class ClubPrive : public Batiment {
public:
    ClubPrive();
    ~ClubPrive() override = default;
    ClubPrive(const ClubPrive& clubPrive) = default;
    Batiment* clone() const override {return new ClubPrive(*this);};
    void declencher_effet(unigned int possesseur) const override;
  
};

#endif 