#include "utils.h"
#define REP_ED_MIN 1
#define REP_ED_MAX 3

#define REP_EXT_MIN 1
#define REP_EXT_MAX 4

void menu () {
    int rep_ed = -1;
    EditionDeJeu * edition;
    vector<EditionDeJeu *> listing_extension;

    cout << "/********\tMenu\t********/" << endl;
    while (!(REP_ED_MIN <= rep_ed && rep_ed <= REP_ED_MAX)) {
        cout << "\nVeuillez-choisir une edition :\n"
                "\t1. Standard\n"
                "\t2. Deluxe\n"
                "\t3. Quitter\n"
                "Votre choix :" << endl;
        cin >> rep_ed;
    }

    if (rep_ed == 1) {
        edition = new EditionDeJeu("Standard");
        int rep_ext = -1;
        while (!(REP_EXT_MIN <= rep_ext && rep_ext <= REP_EXT_MAX)) {
            cout << "Vous avez choisi l'edition standard\n"
                    "Vous pouvez jouer avec des extensions\n"
                    "Avec laquelle voulez-vous jouer ?\n"
                    "\t1. Green-Valley\n"
                    "\t2. Marina\n"
                    "\t3. Les deux (Marina + Green-Valley)\n"
                    "\t4. Aucune\n"
                    "Votre choix :" << endl;
            cin >> rep_ext;
        }
        if (rep_ext == 1)
            listing_extension.push_back(new EditionDeJeu("GreenValley"));
        else if (rep_ext == 2)
            listing_extension.push_back(new EditionDeJeu("Marina"));
        else if (rep_ext == 3) {
            listing_extension.push_back(new EditionDeJeu("GreenValley"));
            listing_extension.push_back(new EditionDeJeu("Marina"));
        }
        else
            cout << "Vous avez choisi de jouer sans extension"<< endl;


    } else if (rep_ed == 2) {
        edition = new EditionDeJeu("Deluxe");
    } else if (rep_ed == 3) {
        cout << "Vous avez choisi de quitter." << endl;
        return;
    }


    if (listing_extension.empty()) {
        Partie ma_partie(edition);
        ma_partie.jouer_partie();
    }
    else {
        Partie ma_partie(edition, listing_extension);
        ma_partie.jouer_partie();
    }

    /// Creation de la partie
    cout << "/********\tFin\t********/" << endl;
}
