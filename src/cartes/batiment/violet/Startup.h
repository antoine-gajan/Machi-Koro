#ifndef SRC_STARTUP_H
#define SRC_STARTUP_H

#include "Batiment.h"

class Startup : public Batiment {
public:
    Startup();
    Startup(const Startup& startup) = default;
    Batiment* clone() const override {return new Startup(*this);};
    void declencher_effet() const;
};


#endif //SRC_STARTUP_H
