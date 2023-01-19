#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "VisuelPartie.h"

#define SCORE_GAGNANT 343

int main()
{
    VisuelPartie         visuelPartie;
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance();

    visuelPartie.afficherInformationJeu();
    partieCulDeChouette->lancerPartie(visuelPartie);
    visuelPartie.afficherJoueurs(*partieCulDeChouette->getJoueurs());

    while(partieCulDeChouette->scoreJoueurActuel() < SCORE_GAGNANT)
    {
        visuelPartie.informationTour(partieCulDeChouette->tourActuel(),
                                     *partieCulDeChouette->getJoueurs());

        partieCulDeChouette->lancerDes();
        visuelPartie.afficherDes(partieCulDeChouette->getDes());
        visuelPartie.afficherRegleUtilisee(
          partieCulDeChouette->regleUtilisee());
        partieCulDeChouette->prochainTour();

        if(partieCulDeChouette->scoreJoueurActuel() >= SCORE_GAGNANT)
        {
            visuelPartie.afficherGagnant(partieCulDeChouette->tourActuel(),
                                         *partieCulDeChouette->getJoueurs());
        }
    }

    return 0;
}
