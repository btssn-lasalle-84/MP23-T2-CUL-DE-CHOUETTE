#ifndef PARTIE_H
#define PARTIE_H

class De;

enum Regle;

class PartieCulDeChouette
{
    private:
        bool estTerminee;
        unsigned int nbJoueurs;
        Regle regle;
        De* de;
}

#endif