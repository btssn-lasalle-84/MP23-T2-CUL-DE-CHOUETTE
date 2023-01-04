#ifndef JOUEUR_H
#define JOUEUR_H

#define START_SCORE 0
class Joueur
{
  private:
    string       nom;
    unsigned int score;
    bool         aGagne;

  public:
    Joueur(string nom = "", unsigned int score = "START_SCORE", bool aGagne = false);
    string       getNom() const;
    unsigned int getScore() const;
    void         setNom(string nom);
    void         setScore(unsigned score);
    bool         aGagne();
}
#endif // JOUEUR_H
