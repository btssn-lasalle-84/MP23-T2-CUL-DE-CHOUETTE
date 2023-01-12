#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string& nom) : nom(nom), score(SCORE_DEBUT)
{
}

string Joueur::getNom() const
{
    return nom;
}

unsigned int Joueur::getScore() const
{
    return score;
}

void Joueur::setScore(unsigned int score)
{
    this->score += score;
}
