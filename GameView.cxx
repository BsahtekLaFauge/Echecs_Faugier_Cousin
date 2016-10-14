#include "GameView.h"
#include <iostream>
using namespace std;

GameView::GameView()
{
    m_gameModel = new GameModel();
}

void GameView::affiche() const{
    m_gameModel->getJoueurBlanc()->affiche();
    m_gameModel->getJoueurNoir()->affiche();
    m_gameModel->getEchiquier()->affiche();
}

GameModel* GameView::getGameModel() const {
    return m_gameModel;
}

Piece* GameView::choisirPiece() const {
    int x;
    int y;
    bool ok = false;
    Piece* p;
    while (!ok) {
        cout << "Position x : ";
        cin >> x;
        cout << endl;
        cout << "Position y : ";
        cin >> y;
        cout << endl;
        if (m_gameModel->getEchiquier()->getPiece(x,y) != NULL && m_gameModel->getEchiquier()->getPiece(x,y)->isWhite() == m_gameModel->isWhite()) {
            p = m_gameModel->getEchiquier()->getPiece(x,y);
            ok = true;
        }
        else {
            cout <<"Position invalide"<<endl;
        }
    }
    return p;
}

void GameView::choisirPlacement(Piece *p) {
    int x;
    int y;
    bool ok = false;
    while (!ok) {
        cout << "Destination x : ";
        cin >> x;
        cout << endl;
        cout << "Destination y : ";
        cin >> y;
        cout << endl;
        if (p->mouvementValide(m_gameModel->getEchiquier(),x,y)) {
            m_gameModel->getEchiquier()->deplacer(p,x,y);
            ok = true;
        }
        else {
            cout <<"Destination invalide"<<endl;
        }
    }
}
