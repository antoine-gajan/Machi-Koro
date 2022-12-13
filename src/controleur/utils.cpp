#include "utils.h"
#define REP_ED_MIN 1
#define REP_ED_MAX 3

#define REP_EXT_MIN 1
#define REP_EXT_MAX 4

void menu () {
    Partie* partie = Partie::get_instance();
    partie->jouer_partie();

    /// Creation de la partie
    cout << "/********\tFin\t********/" << endl;
}
