#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "View.h"
int main()
{
    View                 view;
    PartieCulDeChouette* partieCulDeChouette;

    partieCulDeChouette->lancerPartie(view);
    // partieCulDeChouette->lancerDe();

    return 0;
}
