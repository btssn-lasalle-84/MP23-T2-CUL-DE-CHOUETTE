#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"
#include "View.h"
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

PartieCulDeChouette* PartieCulDeChouette::instance = nullptr;

PartieCulDeChouette::PartieCulDeChouette() : nbJoueurs(0), numeroTour(0)
{
    for(int i = 0; i < NB_DES; i++)
    {
        De* de = new De;
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

unsigned int PartieCulDeChouette::tourActuel() const
{
    return this->numeroTour;
}

unsigned int PartieCulDeChouette::prochainTour()
{
    if(numeroTour == (nbJoueurs - 1))
    {
        numeroTour = 0;
    }
    else
    {
        numeroTour += 1;
    }

    return this->numeroTour;
}

unsigned int PartieCulDeChouette::scoreJoueurActuel() const
{
    return this->joueurs[numeroTour].getScore();
}

vector<Joueur> PartieCulDeChouette::getJoueurs() const
{
    return this->joueurs;
}

void PartieCulDeChouette::detruireInstance()
{
    instance->~PartieCulDeChouette();
}

void PartieCulDeChouette::setNbJoueurs(unsigned int nbJoueurs)
{
    this->nbJoueurs = nbJoueurs;
}

void PartieCulDeChouette::lancerPartie(View& view)
{
    string       nom;
    unsigned int nbJoueurs = view.saisirNbJoueurs();

    instance->setNbJoueurs(nbJoueurs);

    for(unsigned int i = 0; i < nbJoueurs; i++)
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
}

void PartieCulDeChouette::regleUtilisee()
{
    unsigned int score = 0;

    sort(des.begin(), des.end());

    if((des[0]->getValeur() == des[1]->getValeur()) ||
       (des[1]->getValeur() == des[2]->getValeur()))
    {
        if(des[0]->getValeur() == des[1]->getValeur())
        {
            score = pow(des[0]->getValeur(), 2);
        }
        else
        {
            score = pow(des[2]->getValeur(), 2);
        }
    }

    else if(des[0]->getValeur() + des[1]->getValeur() == des[2]->getValeur())
    {
        unsigned int velute = des[0]->getValeur() + des[1]->getValeur();
        score               = DOUBLE * pow(velute, 2);
    }

    else if((des[0]->getValeur() == des[1]->getValeur()) &&
            (des[1]->getValeur() == des[2]->getValeur()))
    {
        score = (des[0]->getValeur() * 10) + 40;
    }
    else
    {
        for(unsigned int i = 0; i < NB_DES; i++)
        {
            score += des[i]->getValeur();
        }
    }

    joueurs[numeroTour].setScore(score);
};
