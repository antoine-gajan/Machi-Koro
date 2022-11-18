#include "EntrepriseDeTravauxPublics.h"

EntrepriseDeTravauxPublics::EntrepriseDeTravauxPublics(string path_image)
        : Batiment("Entreprise de travaux publics",
                   2,
                   "Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, vous recevez 8 pièces de la banque.",
                   path_image,
                   Vert,
                   {4},
                   "Entreprise") {}

