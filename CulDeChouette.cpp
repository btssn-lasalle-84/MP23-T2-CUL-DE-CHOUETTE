#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "VisuelPartie.h"

#define SCORE_GAGNANT 343

int main()
{
    VisuelPartie         visuelpartie;
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance();

    visuelpartie.afficherInformationLogiciel();
    partieCulDeChouette->lancerPartie(visuelpartie);
    visuelpartie.afficherJoueurs(partieCulDeChouette->getJoueurs());

    for(unsigned int i = 0;
        partieCulDeChouette->scoreJoueurActuel() < SCORE_GAGNANT;
        i++)
    {
        visuelpartie.informerTour(partieCulDeChouette->tourActuel(),
                                  partieCulDeChouette->getJoueurs());

        partieCulDeChouette->lancerDes();
        partieCulDeChouette->regleUtilisee();
        partieCulDeChouette->prochainTour();
    }

    return 0;
}
