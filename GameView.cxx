#include "GameView.h"

GameView::GameView()
{
    m_gameModel = new GameModel();
}

void GameView::affiche() const{
    m_gameModel->getJoueurBlanc()->affiche();
    m_gameModel->getJoueurNoir()->affiche();
    m_gameModel->getEchiquier()->affiche();
}
