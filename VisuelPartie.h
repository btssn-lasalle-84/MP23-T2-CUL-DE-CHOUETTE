#ifndef VisuelPartie_H
#define VisuelPartie_H

#include <vector>
#include <string>

class Joueur;

class PartieCulDeChouette;

class VisuelPartie
{
  public:
    VisuelPartie();
    ~VisuelPartie();

    unsigned int saisirNbJoueurs();
    std::string  saisirNom(unsigned int numeroJoueur) const;

    void afficherInformationLogiciel() const;
    void afficherJoueurs(std::vector<Joueur> joueurs) const;
    void informerTour(unsigned int tour, std::vector<Joueur> joueurs) const;
};

#endif // VisuelPartie_H