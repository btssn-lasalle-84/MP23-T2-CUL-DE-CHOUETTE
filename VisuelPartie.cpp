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

unsigned int VisuelPartie::choisirScoreGagnant()
{
    unsigned int nouveauScore;

    cout << "Niveau Facile: 100\n"
         << "Niveau Moyen: 250\n"
         << "Niveau compliqué: 343\n"
         << "Choissisez le score ";

    cin >> nouveauScore;

    return nouveauScore;
}

unsigned int VisuelPartie::choisirNombreDePartie()
{
    unsigned int nbDePartie;

    cout << "Combien de partie voulez-vous jouer ? ";
    cin >> nbDePartie;

    return nbDePartie;
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
    cout << setfill('=') << setw(85) << "\n"
         << "Bienvenue dans le jeu cul de chouette. Ce jeu est une "
            "implémantion de celui existant"
            "dans la célèbre série Kaamelott.\n"
         << "Le jeu est divisé en 3 niveaux de difficulté, la difficulté étant "
            "choisi grâce au nombre de points pour gagner.\n"
         << "Les règles qui sont criées ont été enlevé pour une question de "
            "pratique.\n"
         << "Version 2.0\n"
         << setfill('=') << setw(85) << "\n"
         << endl;
}

void VisuelPartie::informationPartie(unsigned int    scoreGagnant,
                                     vector<Joueur>& joueurs)
{
    for(vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end();
        ++it)
    {
        cout << it->getNom() << ", ";
    }

    cout << "pour gagner la partie les joueurs doivent atteindre un score de "
         << to_string(scoreGagnant) << "." << endl;
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
    cout << joueurs[numeroDuTour].getNom() << " a gagné !!! avec un score de "
         << to_string(joueurs[numeroDuTour].getScore()) << endl;
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

void VisuelPartie::lancementDes()
{
    cin.ignore();
    cout << "Lancer les des !!! (appuyer sur entree)\n";
    do
    {
    } while(cin.get() != '\n');
}

void VisuelPartie::afficherDes(vector<De*> des)
{
    for(unsigned int i = 0; i < NB_DES; i++)
    {
        cout << to_string((des[i]->getValeur())) << " ";
    }

    cout << endl;
}
