#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

class De;

class Joueur;

enum Regle
{
    Chouette,
    Velute,
    CulDeChouette
};

class PartieCulDeChouette
{
  private:
    bool                 estTerminee;
    unsigned int         nbJoueurs;
    Regle                regle;
    std::vector<Joueur*> joueurs;
    De*                  de;

  public:
    PartieCulDeChouette(unsigned int nbJoueurs, Regle& regle);
    ~PartieCulDeChouette();

    void setDe(De* de);
    void setJoueurs(std::vector<Joueur*> joueurs);
};

#endif