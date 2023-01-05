#include "PartieCulDeChouette.h"
#include "Joueur.h"
#include "De.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

PartieCulDeChouette* PartieCulDeChouette::instance = nullptr;

PartieCulDeChouette::PartieCulDeChouette(unsigned int nbJoueurs) :
    nbJoueurs(nbJoueurs)
{
    for(int i = 0; i < NB_DES; i++)
    {
        this->des.push_back(nullptr);
    }
}

PartieCulDeChouette::~PartieCulDeChouette()
{
    for(vector<De*>::iterator it = des.begin(); it != des.end(); ++it)
    {
        delete *it;
    }
}

void PartieCulDeChouette::setDes()
{
    De* de = nullptr;
    for(int i = 0; i < NB_DES; i++)
    {
        de = new De;
        this->des.push_back(de);
    }
}

void PartieCulDeChouette::saisirNoms()
{
    string nom;

    for(unsigned int i = 0; i < nbJoueurs; i++)
    {
        cout << "Nom Joueur : " << '\n';
        cin >> nom;
        joueurs.push_back(Joueur(nom));
    }
}

void PartieCulDeChouette::afficherPartie() const
{
    cout << setfill('#') << setw(30) << endl;
    cout << "Nombre Joueurs : " << to_string(this->nbJoueurs) << endl;
    for(unsigned int i = 0; i < nbJoueurs; i++)
    {
        cout << "Score " << this->joueurs[i].getNom() << " : "
             << to_string(this->joueurs[i].getScore()) << endl;
    }
    cout << setfill('#') << setw(30) << endl;
}

PartieCulDeChouette* PartieCulDeChouette::getInstance(unsigned int nbJoueurs)
{
    if(instance == nullptr)
    {
        instance = new PartieCulDeChouette(nbJoueurs);
    }

    return instance;
}

void PartieCulDeChouette::detruireInstance()
{
    instance->~PartieCulDeChouette();
}

void PartieCulDeChouette::lancerPartie()
{
    instance->setDes();
    instance->saisirNoms();
    instance->afficherPartie();
}

void PartieCulDeChouette::lancerDe()
{
    for (int i=0; i < NB_DES; i++)
    {
    cout << i << '\n';
    des[i] -> lancer();
    }
};