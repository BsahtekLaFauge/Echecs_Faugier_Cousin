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
    bool m_echecEtMat;
    bool m_white;
public:
    GameModel();
    Echiquier* getEchiquier();
    JoueurBlanc* getJoueurBlanc();
    JoueurNoir* getJoueurNoir();
    bool getEchecEtMat() const;
    bool isWhite() const;
};

#endif // GAMEMODEL_H
