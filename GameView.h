#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "GameModel.h"

class GameView
{
    GameModel* m_gameModel;
public:
    GameView();
    void affiche() const;
    GameModel* getGameModel() const;
    Piece* choisirPiece() const;
    void choisirPlacement();
};

#endif // GAMEVIEW_H
