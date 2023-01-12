#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "View.h"

#define SCORE_GAGNANT 343

int main()
{
    View                 view;
    PartieCulDeChouette* partieCulDeChouette =
      PartieCulDeChouette::getInstance();

    partieCulDeChouette->lancerPartie(view);
    view.afficherJoueurs(partieCulDeChouette->getJoueurs());
    while (true)
    {
        view.infoTour(partieCulDeChouette->tourActuel(), partieCulDeChouette->getJoueurs());
        partieCulDeChouette->lancerDes();
        partieCulDeChouette->regleUtilisee();
        if (partieCulDeChouette->scoreJoueurActuel() >= SCORE_GAGNANT)
        {
            break;
        }
        partieCulDeChouette->prochainTour();
    }

    return 0;
}
