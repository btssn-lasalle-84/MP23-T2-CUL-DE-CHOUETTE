#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include <iostream>

using namespace std;

int main()
{
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance(nbJoueurs);

    partieCulDeChouette->lancerPartie();
    partieCulDeChouette->lancerDe();

    return 0;
}
