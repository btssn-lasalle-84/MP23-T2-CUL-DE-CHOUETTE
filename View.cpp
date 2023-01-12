#include "View.h"
#include "Joueur.h"
#include "PartieCulDeChouette.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

View::View()
{
}

View::~View()
{
}

unsigned int View::saisirNbJoueurs()
{
    unsigned int nbJoueurs;

    cout << "Entrée nombre joueur." << '\n';
    cin >> nbJoueurs;

    return nbJoueurs;
}

string View::saisirNom(unsigned int numeroJoueur) const
{
    string nom;

    cout << "Nom du Joueur " << to_string(numeroJoueur) << " : " << endl;
    cin >> nom;

    return nom;
}

void View::afficherJoueurs(vector<Joueur> joueurs) const
{
    for(vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end();
        ++it)
    {
        cout << it->getNom() << " : " << to_string(it->getScore()) << " pts "
             << endl;
    }
}