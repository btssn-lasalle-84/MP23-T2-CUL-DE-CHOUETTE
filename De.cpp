#include <stdlib>
#include <time>
#include "De.h"

using namespace std;

De::De(unsigned int valeur, unsigned int nbFaces /*=FACES*/) :
    valeur(valeur), nbFaces(nbFaces)
{
}

De::~De()
{
}

void De::lancer() const
{
    srand(time(NULL));
    this->valeur = rand() % 7 + 1;
}

unsigned int De::getValeur() const
{
    return this->valeur;
}
