#ifndef DE_H
#define DE_H

#define FACES 7

class De
{
  private:
    unsigned int valeur;
    unsigned int nbFaces;

  public:
    De(unsigned int valeur, unsigned int nbFaces = FACES);
    ~De();

    void         lancer() const;
    unsigned int getValeur() const;
}
#endif // DE_H
