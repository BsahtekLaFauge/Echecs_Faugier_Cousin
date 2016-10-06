
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

  gV->affiche();

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1
}
