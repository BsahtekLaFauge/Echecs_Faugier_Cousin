#include "GameModel.h"

GameModel::GameModel()
{
    m_Echiquier = new Echiquier();
    m_jWhite = new JoueurBlanc();
    m_jBlack = new JoueurNoir();
    m_jBlack->placerPieces(*m_Echiquier);
    m_jWhite->placerPieces(*m_Echiquier);
}
