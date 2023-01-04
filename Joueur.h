#ifndef JOUEUR_H
#define JOUEUR_H

#define SCORE_DEBUT 0

#include <string>

class Joueur
{
  private:
    std::string  nom;
    unsigned int score;
    bool         aGagne;

  public:
    Joueur(std::string& nom);
    std::string  getNom() const;
    unsigned int getScore() const;
    void         setNom(std::string& nom);
    void         setScore(unsigned int score);
};
#endif // JOUEUR_H
