#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include "Joueur.h"
#include "Echiquier.h"

class GameModel
{
private:
    JoueurBlanc* m_jWhite;
    JoueurNoir* m_jBlack;
    Echiquier* m_Echiquier;
public:
    GameModel();
    Echiquier* getEchiquier();
    JoueurBlanc* getJoueurBlanc();
    JoueurNoir* getJoueurNoir();
};

#endif // GAMEMODEL_H
