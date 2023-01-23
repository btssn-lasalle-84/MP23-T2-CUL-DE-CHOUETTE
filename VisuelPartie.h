#ifndef VisuelPartie_H
#define VisuelPartie_H

#include <vector>
#include <string>

class Joueur;

class De;

class PartieCulDeChouette;

class VisuelPartie
{
  public:
    VisuelPartie();
    ~VisuelPartie();

    unsigned int saisirNbJoueurs();
    unsigned int choisirScoreGagnant();
    unsigned int choisirNombreDePartie();
    std::string  saisirNom(unsigned int numeroJoueur);

    void afficherInformationJeu();
    void afficherJoueurs(std::vector<Joueur>& joueurs);
    void informationTour(unsigned int         numeroDuTour,
                         std::vector<Joueur>& joueurs);
    void afficherGagnant(unsigned int         numeroDuTour,
                         std::vector<Joueur>& joueurs);
    void afficherRegleUtilisee(unsigned int regleUtilisee);
    void afficherDes(std::vector<De*> de);
};

#endif // VisuelPartie_H