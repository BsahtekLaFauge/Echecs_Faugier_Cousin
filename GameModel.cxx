#include "GameModel.h"

GameModel::GameModel()
{
    m_Echiquier = new Echiquier();
    m_jWhite = new JoueurBlanc();
    m_jBlack = new JoueurNoir();
    m_jBlack->placerPieces(*m_Echiquier);
    m_jWhite->placerPieces(*m_Echiquier);
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
