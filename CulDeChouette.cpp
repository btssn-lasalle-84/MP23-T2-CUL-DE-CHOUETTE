#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "VisuelPartie.h"

int main()
{
    VisuelPartie         visuelPartie;
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance();

    partieCulDeChouette->choisirNombreDePartie(visuelPartie);

    for(unsigned int i = 0; i < partieCulDeChouette->nbDePartie(); i++)
    {
        visuelPartie.afficherInformationJeu();
        partieCulDeChouette->lancerPartie(visuelPartie);
        visuelPartie.informationPartie(partieCulDeChouette->getScoreGagnant(),
                                       *partieCulDeChouette->getJoueurs());

        while(partieCulDeChouette->scoreJoueurActuel() <
              partieCulDeChouette->getScoreGagnant())
        {
            visuelPartie.informationTour(partieCulDeChouette->tourActuel(),
                                         *partieCulDeChouette->getJoueurs());

            partieCulDeChouette->lancerDes(visuelPartie);
            visuelPartie.afficherDes(partieCulDeChouette->getDes());
            visuelPartie.afficherRegleUtilisee(
              partieCulDeChouette->regleUtilisee());
            partieCulDeChouette->prochainTour();

            if(partieCulDeChouette->scoreJoueurActuel() >=
               partieCulDeChouette->getScoreGagnant())
            {
                visuelPartie.afficherGagnant(
                  partieCulDeChouette->tourActuel(),
                  *partieCulDeChouette->getJoueurs());
            }
        }
    }
    return 0;
}
