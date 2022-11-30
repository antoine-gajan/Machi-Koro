#ifndef SRC_MARINA_H
#define SRC_MARINA_H

#include "EditionDeJeu.h"

class Marina : public EditionDeJeu{
    private:
        vector<Batiment> list_bat;
        vector<Monument> list_mon;
    public:
        Marina();
        ~Marina();
};

#endif //SRC_MARINA_H
