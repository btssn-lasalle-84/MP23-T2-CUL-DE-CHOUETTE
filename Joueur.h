#ifndef JOUEUR_H
#define JOUEUR_H

#define SCORE_DEBUT 0

class Joueur
{
  private:
    string       nom;
    unsigned int score;
    bool         aGagne;

  public:
    Joueur(string nom = "", unsigned int score = "SCORE_DEBUT", bool aGagne = false);
    string       getNom() const;
    unsigned int getScore() const;
    void         setNom(string nom);
    void         setScore(unsigned score);
    bool         aGagne();
}
#endif // JOUEUR_H
