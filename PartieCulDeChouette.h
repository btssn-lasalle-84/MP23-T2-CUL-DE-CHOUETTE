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
    PartieCulDeChouette();
    ~PartieCulDeChouette();

    bool                estTerminee;
    unsigned int        nbJoueurs;
    std::vector<Joueur> joueurs;
    std::vector<De*>    des;

    static PartieCulDeChouette* instance;

  public:
    static PartieCulDeChouette* getInstance();
    static void                 detruireInstance();

    void setNbJoueurs(unsigned int nbJoueurs);
    void lancerPartie(View &view);
    void lancerDes();
};

#endif