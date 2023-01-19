#include <random>
#include <chrono>
#include <time.h>
#include "De.h"

using namespace std;

De::De(unsigned int nbFaces /*=FACES*/) : nbFaces(nbFaces)
{
}

De::~De()
{
}

void De::lancer()
{
    static default_random_engine nombre(
      chrono::system_clock::now().time_since_epoch().count());
    static uniform_int_distribution<int> generer(1, 7);
    this->valeur = generer(nombre);
}

unsigned int De::getValeur() const
{
    return this->valeur;
}