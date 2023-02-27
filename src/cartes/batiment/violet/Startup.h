#ifndef SRC_STARTUP_H
#define SRC_STARTUP_H

#include "Batiment.h"

class Startup : public Batiment {
public:
    Startup();
    ~Startup() override = default;
    Startup(const Startup& startup) = default;
    Batiment* clone() const override {return new Startup(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};


#endif //SRC_STARTUP_H
