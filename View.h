#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <string>

class Joueur;

class PartieCulDeChouette;

class View
{
  public:
    View();
    ~View();

    unsigned int saisirNbJoueurs();
    std::string  saisirNom(unsigned int numeroJoueur) const;

    void afficherJoueurs(std::vector<Joueur> joueurs) const;
    void infoTour(unsigned int tour, std::vector<Joueur> joueurs) const;
};

#endif // VIEW_H