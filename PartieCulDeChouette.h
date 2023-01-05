#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#define NB_DES 3

class De;

class Joueur;

class PartieCulDeChouette
{
  private:
    PartieCulDeChouette(unsigned int nbJoueurs);
    ~PartieCulDeChouette();

    bool                estTerminee;
    unsigned int        nbJoueurs;
    std::vector<Joueur> joueurs;
    std::vector<De*>    des;

    void setDes();
    void saisirNoms();
    void afficherPartie() const;

    static PartieCulDeChouette* instance;

  public:
    static PartieCulDeChouette* getInstance(unsigned int nbJoueurs);
    static void                 detruireInstance();

    void  lancerPartie();
    void  lancerDe(); 
};

#endif