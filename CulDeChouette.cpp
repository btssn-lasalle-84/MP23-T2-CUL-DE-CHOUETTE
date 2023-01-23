#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "VisuelPartie.h"

int main()
{
    VisuelPartie         visuelPartie;
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance();

    visuelPartie.afficherInformationJeu();
    partieCulDeChouette->choisirScoreGagnant(visuelPartie);
    partieCulDeChouette->lancerPartie(visuelPartie);
    visuelPartie.afficherJoueurs(*partieCulDeChouette->getJoueurs());

    while(partieCulDeChouette->scoreJoueurActuel() <
          partieCulDeChouette->getScoreGagnant())
    {
        visuelPartie.informationTour(partieCulDeChouette->tourActuel(),
                                     *partieCulDeChouette->getJoueurs());

        partieCulDeChouette->lancerDes();
        visuelPartie.afficherDes(partieCulDeChouette->getDes());
        visuelPartie.afficherRegleUtilisee(
          partieCulDeChouette->regleUtilisee());
        partieCulDeChouette->prochainTour();

        if(partieCulDeChouette->scoreJoueurActuel() >=
           partieCulDeChouette->getScoreGagnant())
        {
            visuelPartie.afficherGagnant(partieCulDeChouette->tourActuel(),
                                         *partieCulDeChouette->getJoueurs());
        }
    }

    return 0;
}
