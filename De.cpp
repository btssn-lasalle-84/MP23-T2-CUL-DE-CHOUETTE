#include <random>
#include <chrono>
#include <time.h>
#include "De.h"

using namespace std;

De::De(unsigned int nbFaces /*=FACES*/) : nbFaces(nbFaces)
{
    srand((unsigned int)time(nullptr));
}

De::~De()
{
}

void De::lancer()
{
    this->valeur = rand() % FACES + 1;
}

unsigned int De::getValeur() const
{
    return this->valeur;
}