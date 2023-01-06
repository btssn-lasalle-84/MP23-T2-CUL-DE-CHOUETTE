#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include <iostream>

using namespace std;

int main()
{
    unsigned int nbJoueurs;
    cout << "Entrée nombre joueur." << '\n';
    cin >> nbJoueurs;

    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance(nbJoueurs);

    partieCulDeChouette->lancerPartie();
    partieCulDeChouette->lancerDe();

    return 0;
}
