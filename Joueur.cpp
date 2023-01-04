#include Joueur_H

using namespace std;

Joueur::Joueur(string nom = "", unsigned int score = "SCORE_DEBUT", bool aGagne = false)
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

bool aGagne()
{
    if(getScore() >= 500)
    {
        return true;
    }
    else
    {
        return false;
    }
}