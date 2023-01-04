#include "Joueur.h"

using namespace std;

Joueur::Joueur(string nom) : nom(nom), score(SCORE_DEBUT)
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

void setNom(string nom)
{
    this->nom = nom;
}

void setScore(unsigned int score)
{
    this->score = score;
}
