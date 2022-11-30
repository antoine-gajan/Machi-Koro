#include <iostream>

/// Importation des classes monuments
#include "Batiment.h"
#include "BanqueDeMinivilles.h"
#include "Boulangerie.h"
#include "EntrepriseDeDemenagement.h"
#include "EntrepriseDeTravauxPublics.h"
#include "Epicerie.h"
#include "FabriqueDeMeubles.h"
#include "Fleuriste.h"
#include "Fromagerie.h"
#include "HalleDeMarche.h"
#include "MarcheDeFruitsEtLegumes.h"
#include "MoonsterSoda.h"
#include "Superette.h"

using namespace std;

int main()
{
    BanqueDeMinivilles banqueDeMinivilles;
    banqueDeMinivilles.declencher_effet();

    Boulangerie boulangerie;
    boulangerie.declencher_effet();

    EntrepriseDeDemenagement entrepriseDeDemenagement;
    entrepriseDeDemenagement.declencher_effet();

    EntrepriseDeTravauxPublics entrepriseDeTravauxPublics;
    entrepriseDeTravauxPublics.declencher_effet();

    Epicerie epicerie;
    epicerie.declencher_effet();

    FabriqueDeMeubles fabriqueDeMeubles;
    fabriqueDeMeubles.declencher_effet();

    Fleuriste fleuriste;
    fleuriste.declencher_effet();

    Fromagerie fromagerie;
    fromagerie.declencher_effet();

    HalleDeMarche halleDeMarche;
    halleDeMarche.declencher_effet();

    MarcheDeFruitsEtLegumes marcheDeFruitsEtLegumes;
    marcheDeFruitsEtLegumes.declencher_effet();

    MoonsterSoda moonsterSoda;
    moonsterSoda.declencher_effet();

    Superette superette;
    superette.declencher_effet();

    return 0;
}