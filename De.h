#include <random>

#ifndef DE_H
#define DE_H

#define FACES 6

class De
{
  private:
    unsigned int valeur;
    unsigned int nbFaces;

  public:
    De(unsigned int nbFaces = FACES);
    ~De();

    void         lancer();
    unsigned int getValeur() const;

    friend bool operator<(const De& de1, const De& de2)
    {
        return (de1.getValeur() < de2.getValeur());
    }
};

#endif // DE_H
