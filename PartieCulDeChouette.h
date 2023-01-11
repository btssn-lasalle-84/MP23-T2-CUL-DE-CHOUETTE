#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#define NB_DES 3

class De;

class Joueur;

class View;

class PartieCulDeChouette
{
  private:
    PartieCulDeChouette(unsigned int nbJoueurs);
    ~PartieCulDeChouette();

    bool                estTerminee;
    unsigned int        numeroTour;
    unsigned int        nbJoueurs;
    std::vector<Joueur* > joueurs;
    std::vector<De*>    des;

    static PartieCulDeChouette* instance;

  public:
    static PartieCulDeChouette* getInstance(unsigned int nbJoueurs);
    static void                 detruireInstance();

    void lancerPartie(View& view);
    void lancerDes();
    void implementationScore();
};

#endif