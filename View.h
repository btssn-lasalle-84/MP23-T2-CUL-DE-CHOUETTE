#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <string>

class Joueur;

class PartieCulDeChouette;

class View
{
  private:
    unsigned int        nbJoueurs;
    std::vector<Joueur> joueurs;

  public:
    View();
    ~View();
    void saisirNbJoueurs();
    void saisirNoms() const;
    void afficherScore() const;
};

#endif // VIEW_H