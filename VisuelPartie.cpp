#include "VisuelPartie.h"
#include "Joueur.h"
#include "De.h"
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

string VisuelPartie::saisirNom(unsigned int numeroJoueur)
{
    string nom;

    cout << "Nom du Joueur "
         << " : ";
    cin >> nom;

    return nom;
}

void VisuelPartie::afficherInformationJeu()
{
    cout << "Bienvenue dans le jeu cul de chouette ,"
         << " la version du jeu est la 1.0 " << endl;
}
void VisuelPartie::afficherJoueurs(vector<Joueur>& joueurs)
{
    for(vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end();
        ++it)
    {
        cout << it->getNom() << " : " << to_string(it->getScore()) << " pts "
             << endl;
    }
}

void VisuelPartie::informationTour(unsigned int    numeroDuTour,
                                   vector<Joueur>& joueurs)
{
    cout << "Score de " << joueurs[numeroDuTour].getNom() << " : "
         << to_string(joueurs[numeroDuTour].getScore()) << endl;
}

void VisuelPartie::afficherGagnant(unsigned int    numeroDuTour,
                                   vector<Joueur>& joueurs)
{
    cout << joueurs[numeroDuTour].getNom() << " a gagné !!!" << endl;
}

void VisuelPartie::afficherRegleUtilisee(unsigned int regleUtilisee)
{
    switch(regleUtilisee)
    {
        case 1:
            cout << "Vous avez fait une Chouette ! C'est Chouette :)" << endl;
            break;
        case 2:
            cout << "Vous avez fait un Velute !" << endl;
            break;
        case 3:
            cout << "Vous avec le nez dans le Cul de la Chouette !" << endl;
            break;
        default:
            cout << "Peut être qu'au prochain tour vous ferez quelque chose "
                    "d'utile ;)"
                 << endl;
            break;
    }
}

void VisuelPartie::afficherDes(vector<De*> des)
{
    for(unsigned int i = 0; i < NB_DES; i++)
    {
        cout << to_string(des[i]->getValeur()) << " ";
    }

    cout << endl;
}
