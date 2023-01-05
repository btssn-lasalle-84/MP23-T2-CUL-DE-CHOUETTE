#include <stdlib.h>
#include <time.h>
#include "De.h"

using namespace std;

De::De(unsigned int nbFaces /*=FACES*/) :
    nbFaces(nbFaces)
{
}

De::~De()
{
}

void De::lancer()
{
    srand(time(nullptr));
    this->valeur = rand() % FACES + 1;
}

unsigned int De::getValeur() const
{
    return this->valeur;
}
