#include "VisuelPartie.h"
#include "Joueur.h"
#include "PartieCulDeChouette.h"
#include <iostream>
#include <iomanip>

using namespace std;

VisuelPartie::VisuelPartie()
{
}

VisuelPartie::~VisuelPartie()
{
}

unsigned int VisuelPartie::saisirNbJoueurs()
{
    unsigned int nbJoueurs;

    cout << "Entrée le nombre de joueurs "
         << " : ";
    cin >> nbJoueurs;

    return nbJoueurs;
}

string VisuelPartie::saisirNom(unsigned int numeroJoueur) const
{
    string nom;

    cout << "Nom du Joueur "
         << " : ";
    cin >> nom;

    return nom;
}

void VisuelPartie::afficherInformationLogiciel() const
{
    cout << "Bienvenue dans le jeu cul de chouette ,"
         << " la version du jeu est la 1.0 " << endl;
}
void VisuelPartie::afficherJoueurs(vector<Joueur> joueurs) const
{
    for(vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end();
        ++it)
    {
        cout << it->getNom() << " : " << to_string(it->getScore()) << " pts "
             << endl;
    }
}

void VisuelPartie::informerTour(unsigned int tour, vector<Joueur> joueurs) const
{
    cout << "Score de " << joueurs[tour].getNom() << " : "
         << to_string(joueurs[tour].getScore()) << endl;
}