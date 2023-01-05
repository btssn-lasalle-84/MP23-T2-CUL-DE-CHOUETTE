#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#define REGLE_DEFAUT Chouette
#define NB_DES       3

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
    PartieCulDeChouette(unsigned int nbJoueurs);
    ~PartieCulDeChouette();

    bool                estTerminee;
    unsigned int        nbJoueurs;
    Regle               regle;
    std::vector<Joueur> joueurs;
    std::vector<De*>    des;

    void setDes();
    void saisirNoms();
    void choisirRegles(Regle regle);
    void afficherPartie() const;

    static PartieCulDeChouette* instance;

  public:
    static PartieCulDeChouette* getInstance(unsigned int nbJoueurs);
    static void                 detruireInstance();

    void lancerPartie();
};

#endif