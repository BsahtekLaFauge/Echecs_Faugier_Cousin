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
    if (m_gameModel->isWhite())
        cout << "Au tour du joueur blanc"<<endl;
    else
        cout << "Au tour du joueur noir"<<endl;
}

GameModel* GameView::getGameModel() const {
    return m_gameModel;
}

Piece* GameView::choisirPiece() const {
    int x;
    int y;
    Piece* p = NULL;
    while (p == NULL) {
        cout << "Position x : ";
        cin >> x;
        cout << endl;
        cout << "Position y : ";
        cin >> y;
        cout << endl;
        p = m_gameModel->testerCoordonnees(x,y);
    }
    return p;
}

void GameView::choisirPlacement(Piece *p) {
    int x;
    int y;
    cout << "Destination x : ";
    cin >> x;
    cout << endl;
    cout << "Destination y : ";
    cin >> y;
    cout << endl;
    m_gameModel->choisirPlacement(p,x,y);
}

void GameView::changerJoueur() {
    m_gameModel->changerJoueur();
}
