#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#define NB_DES 3
#define DOUBLE 2

class De;

class Joueur;

class VisuelPartie;

class PartieCulDeChouette
{
  private:
    bool                estTerminee;
    unsigned int        numeroTour;
    unsigned int        nbJoueurs;
    std::vector<Joueur> joueurs;
    std::vector<De*>    des;

    PartieCulDeChouette();
    ~PartieCulDeChouette();

    static PartieCulDeChouette* instance;

  public:
    static PartieCulDeChouette* getInstance();
    static void                 detruireInstance();

    unsigned int         tourActuel() const;
    unsigned int         prochainTour();
    unsigned int         scoreJoueurActuel() const;
    std::vector<Joueur>* getJoueurs() const;
    std::vector<De*>     getDes() const;

    void         setNbJoueurs(unsigned int nbJoueurs);
    void         lancerPartie(VisuelPartie& visuelpartie);
    void         lancerDes();
    unsigned int regleUtilisee();
};

#endif