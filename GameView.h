#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "GameModel.h"

class GameView
{
    GameModel* m_gameModel;
public:
    GameView();
    void affiche() const;
};

#endif // GAMEVIEW_H
