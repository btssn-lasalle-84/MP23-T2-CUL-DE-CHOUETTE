#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"
#include "View.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

PartieCulDeChouette* PartieCulDeChouette::instance = nullptr;

PartieCulDeChouette::PartieCulDeChouette(unsigned int nbJoueurs) :
    nbJoueurs(nbJoueurs), des(NB_DES, new De)
{
}

PartieCulDeChouette::~PartieCulDeChouette()
{
    for(vector<De*>::iterator it = des.begin(); it != des.end(); ++it)
    {
        delete *it;
    }
}

PartieCulDeChouette* PartieCulDeChouette::getInstance(unsigned int nbJoueurs)
{
    if(instance == nullptr)
    {
        instance = new PartieCulDeChouette(nbJoueurs);
    }

    return instance;
}

void PartieCulDeChouette::detruireInstance()
{
    instance->~PartieCulDeChouette();
}

void PartieCulDeChouette::lancerPartie(View& view)
{
    view.saisirNbJoueurs();
    view.saisirNoms();
}

void PartieCulDeChouette::lancerDes()
{
    for(int i = 0; i < NB_DES; i++)
    {
        this->des[i]->lancer();
    }
};