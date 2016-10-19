#include "GameModel.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

GameModel::GameModel()
{
    m_Echiquier = new Echiquier();
    m_jWhite = new JoueurBlanc();
    m_jBlack = new JoueurNoir();
    m_jBlack->placerPieces(*m_Echiquier);
    m_jWhite->placerPieces(*m_Echiquier);
    m_echecEtMat = false;
    m_white = true;
    m_played = false;
}

Echiquier* GameModel::getEchiquier() {
    return m_Echiquier;
}

JoueurBlanc* GameModel::getJoueurBlanc() {
    return m_jWhite;
}

JoueurNoir* GameModel::getJoueurNoir() {
    return m_jBlack;
}

bool GameModel::getEchecEtMat() const {
    return m_echecEtMat;
}

bool GameModel::isWhite() const {
    return m_white;
}

void GameModel::changerJoueur() {
    if (m_played)
        m_white = !m_white;
}

void GameModel::played() {
    m_played = !m_played;
}

Piece* GameModel::testerCoordonnees(int x,int y) const{
    assert(x<9 && x>0 && y<9 && y>0);
    if (m_Echiquier->getPiece(x,y) == NULL || m_Echiquier->getPiece(x,y)->isWhite() != m_white) {
        cout << "Position invalide"<<endl;
        return NULL;
    }
    else  {
        return m_Echiquier->getPiece(x,y);
    }

}

void GameModel::choisirPlacement(Piece *p,int x,int y) {
    assert(x<9 && x>0 && y<9 && y>0);
    if (p->mouvementValide(m_Echiquier,x,y)) {
        m_Echiquier->deplacer(p,x,y);
        m_played = true;
    }
    else
        cout <<"Destination invalide"<<endl;
}
