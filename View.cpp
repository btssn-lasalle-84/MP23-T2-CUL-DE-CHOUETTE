#include "View.h"
#include "Joueur.h"
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

void View::saisirNbJoueurs()
{
    cout << "Entrée nombre joueur." << '\n';
    cin >> nbJoueurs;
}

void View::saisirNoms() const
{
    string nom;

    for(unsigned int i = 0; i < nbJoueurs; i++)
    {
        cout << "Nom Joueur : " << '\n';
        cin >> nom;
    }
    cout << setfill('#') << setw(30) << '\n';
    cout << "Nombre Joueurs : " << to_string(this->nbJoueurs) << endl;
    cout << setfill('#') << setw(30) << '\n';
}

void View::afficherScore() const
{
    for(unsigned int i = 0; i < nbJoueurs; i++)
    {
        cout << "Score " << this->joueurs[i].getNom() << " : "
             << to_string(this->joueurs[i].getScore()) << endl;
    }
}