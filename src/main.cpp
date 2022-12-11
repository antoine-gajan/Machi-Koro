#include <iostream>
using namespace std;

#include "Partie.h"

int main() {
    Partie* p = Partie::get_instance();

    p->jouer_partie();

    return 0;
}