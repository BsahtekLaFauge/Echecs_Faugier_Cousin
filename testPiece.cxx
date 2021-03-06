
/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "GameView.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  GameView* gV = new GameView();
  Piece* p;
  while (!gV->getGameModel()->getEchecEtMat()) {
        gV->affiche();
        p = gV->choisirPiece();
        p->affiche();
        gV->choisirPlacement(p);
        gV->changerJoueur();
  }
}
