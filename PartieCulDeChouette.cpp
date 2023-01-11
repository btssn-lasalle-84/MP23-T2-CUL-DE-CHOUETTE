#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"
#include "View.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

PartieCulDeChouette* PartieCulDeChouette::instance = nullptr;

PartieCulDeChouette::PartieCulDeChouette() :
    nbJoueurs(0)
{
    De* de;
    for(int i = 0; i < NB_DES; i++)
    {
        de = new De;
        this->des.push_back(de);
    }
}

PartieCulDeChouette::~PartieCulDeChouette()
{
    for(vector<De*>::iterator it = des.begin(); it != des.end(); ++it)
    {
        delete *it;
    }
}

PartieCulDeChouette* PartieCulDeChouette::getInstance()
{
    if(instance == nullptr)
    {
        instance = new PartieCulDeChouette();
    }

    return instance;
}

void PartieCulDeChouette::detruireInstance()
{
    instance->~PartieCulDeChouette();
}

void PartieCulDeChouette::setNbJoueurs(unsigned int nbJoueurs)
{
    this->nbJoueurs = nbJoueurs;
}

void PartieCulDeChouette::lancerPartie(View &view)
{
    string nom;
    unsigned int nbJoueurs = view.saisirNbJoueurs();

    instance->setNbJoueurs(nbJoueurs);

    for (unsigned int i = 0; i < nbJoueurs; i++)
    {
        nom = view.saisirNom(i);
        this->joueurs.push_back(Joueur(nom));
    }
}

void PartieCulDeChouette::lancerDes()
{
    for(int i = 0; i < NB_DES; i++)
    {
        this->des[i]->lancer();
    }
};