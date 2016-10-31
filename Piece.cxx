/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"
#include <cassert>
#include <cmath>

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
  cout << "Construction Piece par defaut" << endl;
}

Piece::~Piece()
{
  cout << "Destruction Piece" << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Construction Piece specialisee" << endl;
}

Roi::Roi( bool white ) : Piece(5,(white)?1:8,white)
{
  cout << "Construction Roi specialisee" << endl;
}

Tour::Tour( bool white, bool left ) : Piece((left)?1:8,(white)?1:8,white)
{
  cout << "Construction Tour specialisee" << endl;
}

Fou::Fou( bool white, bool left ) : Piece((left)?3:6,(white)?1:8,white)
{
  cout << "Construction Fou specialisee" << endl;
}

Cavalier::Cavalier( bool white, bool left ) : Piece((left)?2:7,(white)?1:8,white)
{
  cout << "Construction Cavalier specialisee" << endl;
}

Pion::Pion( bool white, int p ) : Piece(p,(white)?2:7,white)
{
  m_moved = false;
  cout << "Construction Pion specialisee" << endl;
}


Reine::Reine( bool white ) : Piece(4,(white?1:8),white), Fou(white,true), Tour(white,true)
{
  //  m_x = 4;
  //  m_y = (white)?1:8;
  //  m_white = white;
  cout << "Construction Reine specialisee" << endl;
}

Piece::Piece( const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Construction Piece par copie" << endl;
}

Piece &
Piece::operator=( const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Affectation Piece" << endl;
  return *this;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::mouvementValide(Echiquier* e, int x, int y)
{
  cout << "mouvementValide de Piece" << endl;
  return false;
}

char
Piece::myChar()
{
  return m_white?'B':'N';
}

void
Piece::affiche() const{

}

bool
Roi::mouvementValide(Echiquier* e, int x, int y)
{
  cout << "mouvementValide de Roi" << endl;
  return false;
}

char
Roi::myChar()
{
  return m_white?'R':'r';
}

void
Roi::affiche() const
{
  cout << "Roi: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanc" : "noir" ) << endl;
}

bool
Tour::mouvementValide(Echiquier* e, int x, int y)
{
    bool canMove = false;
    assert(x<9 && x>0 && y<9 && y>0);
    if (e->getPiece(x,y) == NULL || e->getPiece(x,y)->isWhite() != m_white) {
        if (m_x == x && m_y != y) {
            int i = m_y;
            canMove = true;
            if (m_y < y) {
                while (i+1 < y && canMove) {
                    i ++;
                    if (e->getPiece(x,i) != NULL)
                        canMove = false;
                }
            }
            else {
                while (i-1 > y && canMove) {
                    i --;
                    if (e->getPiece(x,i) != NULL)
                        canMove = false;
                }
            }
        }
        if (m_y == y && m_x != x) {
            int i = m_x;
            canMove = true;
            if (m_x < x) {
                while (i+1 < x && canMove) {
                    i ++;
                    if (e->getPiece(i,y) != NULL)
                        canMove = false;
                }
            }
            else {
                while (i-1 > x && canMove) {
                    i --;
                    if (e->getPiece(i,y) != NULL)
                        canMove = false;
                }
            }
        }
    }
    return canMove;
}

char
Tour::myChar()
{
  return m_white?'T':'t';
}

void
Tour::affiche() const
{
  cout << "Tour: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}

bool
Fou::mouvementValide(Echiquier* e, int x, int y)
{
  cout << "mouvementValide de Fou" << endl;
  return false;
}

char
Fou::myChar()
{
  return m_white?'F':'f';
}

void
Fou::affiche() const
{
  cout << "Fou: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanc" : "noir" ) << endl;
}

bool
Cavalier::mouvementValide(Echiquier* e, int x, int y)
{
    bool canMove = false;
    assert(x<9 && x>0 && y<9 && y>0);
    if ( abs(m_x-x) < 3 && abs(m_y-y) < 3 && abs(m_x-x)+abs(m_y-y) == 3) {
        if (e->getPiece(x,y) == NULL || e->getPiece(x,y)->isWhite() != m_white)
            canMove = true;
    }
    return canMove;
}

char
Cavalier::myChar()
{
  return m_white?'C':'c';
}

void
Cavalier::affiche() const
{
  cout << "Cavalier: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanc" : "noir" ) << endl;
}

bool
Pion::mouvementValide(Echiquier* e, int x, int y)
{
    bool canMove = false;
    assert(x<9 && x>0 && y<9 && y>0);
    if (m_white) {
        if (x == m_x && y == m_y+2){
            if (!m_moved && e->getPiece(x,y) == NULL && e->getPiece(x,y-1) == NULL) {
                canMove = true;
            }
        }
        if (x == m_x && y == m_y+1){
            if (e->getPiece(x,y) == NULL) {
                canMove = true;
            }
        }
        if (x == m_x+1 && y == m_y+1){
            if (e->getPiece(x,y) != NULL && !e->getPiece(x,y)->isWhite()) {
                canMove = true;
            }
        }
        if (x == m_x-1 && y == m_y+1){
            if (e->getPiece(x,y) != NULL && !e->getPiece(x,y)->isWhite()) {
                canMove = true;
            }
        }
    }
    else {
        if (x == m_x && y == m_y-2){
            if (!m_moved && e->getPiece(x,y) == NULL && e->getPiece(x,y+1) == NULL) {
                canMove = true;
            }
        }
        if (x == m_x && y == m_y-1){
            if (e->getPiece(x,y) == NULL) {
                canMove = true;
            }
        }
        if (x == m_x+1 && y == m_y-1){
            if (e->getPiece(x,y) != NULL && e->getPiece(x,y)->isWhite()) {
                canMove = true;
            }
        }
        if (x == m_x-1 && y == m_y-1){
            if (e->getPiece(x,y) != NULL && e->getPiece(x,y)->isWhite()) {
                canMove = true;
            }
        }
    }
    if (canMove && !m_moved)
        m_moved = true;
  return canMove;
}

char
Pion::myChar()
{
  return m_white?'P':'p';
}

void
Pion::affiche() const
{
  cout << "Pion: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanc" : "noir" ) << endl;
}

bool
Pion::hasMoved() const {
    return m_moved;
}

void
Roi::roque(bool left)
{
  cout << "roque " << (left?"gauche":"droit") << " de Roi" << endl;
}

bool
Reine::mouvementValide(Echiquier* e, int x, int y)
{
  cout << "mouvementValide de Reine" << endl;
  return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

char
Reine::myChar()
{
  return m_white?'Q':'q';
}

void
Reine::affiche() const
{
  cout << "Reine: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}
