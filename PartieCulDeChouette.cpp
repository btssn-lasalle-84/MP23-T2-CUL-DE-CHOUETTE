#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"
#include "View.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

PartieCulDeChouette* PartieCulDeChouette::instance = nullptr;

PartieCulDeChouette::PartieCulDeChouette() : nbJoueurs(0)
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

void PartieCulDeChouette::implementationScore()
{
    unsigned int i;
    unsigned int score;

    if((des[0]->getValeur() == des[1]->getValeur()) ||
       (des[1]->getValeur() == des[2]->getValeur()) ||
       (des[0]->getValeur() == des[2]->getValeur())) // La Chouette
    {
        score = des[i]->getValeur() * des[i++]->getValeur();
        joueurs[numeroTour].setScore(score);
    }

    else if((des[0]->getValeur() + des[1]->getValeur()) ==
            des[i + 2]->getValeur()) //  La Velute
    {
        switch(des[3]->getValeur() > 2)
        {
            case 1:
                des[3]->getValeur() == 3;
                score = 18;
                joueurs[numeroTour].setScore(score);
                break;
            case 2:
                des[3]->getValeur() == 4;
                score = 32;
                joueurs[numeroTour].setScore(score);
                break;
            case 3:
                des[3]->getValeur() == 5;
                score = 50;
                joueurs[numeroTour].setScore(score);
                break;
            case 4:
                des[3]->getValeur() == 6;
                score = 72;
                joueurs[numeroTour].setScore(score);
                break;
            default:
                des[3]->getValeur() < 2;
                score = des[3]->getValeur();
                joueurs[numeroTour].setScore(score);
                break;
        }
    }

    else if((des[0]->getValeur() == des[1]->getValeur() &&
             des[2]->getValeur())) // Le Cul de Chouette
    {
        score = 40 + 10 * i;
        joueurs[numeroTour].setScore(score);
    }
    else
    {
        score = des[0]->getValeur() + des[1]->getValeur() + des[2]->getValeur();
        joueurs[numeroTour].setScore(score);
    }
};
