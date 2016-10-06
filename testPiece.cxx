
/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  Echiquier e;
  e.affiche();

  JoueurBlanc jb;
  JoueurNoir jn;
  jb.affiche();
  jn.affiche();

  jb.placerPieces(e);
  jn.placerPieces(e);

  /*
  ptr=e.enleverPiece(5,1);
  e.placer(&rb);
  ptr=e.enleverPiece(5,8);
  e.placer(&rn);
  ptr=e.enleverPiece(4,1);
  e.placer(&qb);
  ptr=e.enleverPiece(4,8);
  e.placer(&qn);
  */

  e.affiche();

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1
}
