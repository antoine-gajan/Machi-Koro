#ifndef SRC_STARTUP_H
#define SRC_STARTUP_H

#include "Batiment.h"

class Startup : public Batiment {
public:
    Startup();
    void declencher_effet() const;
};


#endif //SRC_STARTUP_H
