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
    unsigned int        scoreGagnant;
    unsigned int        nombreDePartie;
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
    unsigned int         nbDePartie() const;
    unsigned int         getScoreGagnant() const;
    std::vector<Joueur>* getJoueurs() const;
    std::vector<De*>     getDes() const;

    void         setNbJoueurs(unsigned int nbJoueurs);
    void         choisirNombreDePartie(VisuelPartie& visuelPartie);
    void         lancerPartie(VisuelPartie& visuelpartie);
    void         lancerDes(VisuelPartie& visuelPartie);
    unsigned int regleUtilisee();
};

#endif