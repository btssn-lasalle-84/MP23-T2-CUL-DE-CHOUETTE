#include "Joueur.h"
#include "De.h"
#include "PartieCulDeChouette.h"
#include "View.h"

#define SCORE_GAGNANT 500

int main()
{
    View                 view;
    PartieCulDeChouette* partieCulDeChouette;

    partieCulDeChouette->lancerPartie(view);
    /*while (true)
    {
        view->afficherJoueurs();
        partieCulDeChouette->lancerDes();
        partieCulDeChouette->combinaisonUtilisee();
        if (partieCulDeChouette->scoreJoueurActuel() >= SCORE_GAGNANT)
        {
            break;
        }
    }*/

    return 0;
}
