#include "GameModel.h"

GameModel::GameModel()
{
    m_Echiquier = new Echiquier();
    m_jWhite = new JoueurBlanc();
    m_jBlack = new JoueurNoir();
    m_jBlack->placerPieces(*m_Echiquier);
    m_jWhite->placerPieces(*m_Echiquier);
    m_echecEtMat = false;
    m_white = true;
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
    m_white = !m_white;
}
