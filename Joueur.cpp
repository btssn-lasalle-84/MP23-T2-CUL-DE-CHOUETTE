#include "Joueur.h"

using namespace std;

Joueur::Joueur(string& nom) : nom(nom), score(SCORE_DEBUT), aGagne(false)
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

void Joueur::setNom(string& nom)
{
    this->nom = nom;
}

void Joueur::setScore(unsigned int score)
{
    this->score = score;
}
