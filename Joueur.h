#ifndef JOUEUR_H
#define JOUEUR_H

#define SCORE_DEBUT 0

#include <string>

class Joueur
{
  private:
    const std::string nom;
    unsigned int      score;

  public:
    Joueur(const std::string& nom);
    std::string  getNom() const;
    unsigned int getScore() const;
    void         setNom(std::string& nom);
    void         setScore(unsigned int score);
};
#endif // JOUEUR_H
