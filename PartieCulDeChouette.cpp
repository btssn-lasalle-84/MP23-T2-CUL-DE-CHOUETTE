#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"

using namespace std;

PartieCulDeChouette::PartieCulDeChouette(unsigned int nbJoueurs, Regle& regle) :
    nbJoueurs(nbJoueurs), regle(regle), de(nullptr)
{
    for(int i = 0; i < nbJoueurs; i++)
    {
        this->joueurs.push_back(nullptr);
    }
}

PartieCulDeChouette::~PartieCulDeChouette()
{
}

void PartieCulDeChouette::setDe(De* de)
{
    this->de = de;
}

void PartieCulDeChouette::setJoueurs(vector<Joueur*> joueurs)
{
    for(int i = 0; i < nbJoueurs; i++)
    {
        this->joueurs[i] = joueurs[i];
    }
}