/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

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
Piece::isBlack() const
{
  return !m_white;
}

const Piece &
Piece::plusforte(const Piece & autre) const
{
  /* FAUX !!!
  Piece tmp;
  if (true)
    tmp=autre;
  else
    tmp=*this;
  return tmp;
  */
  if (true)
    return autre;
  else
    return *this;
}

bool
Piece::mouvementValide(Echiquier & e, int x, int y)
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
Roi::mouvementValide(Echiquier & e, int x, int y)
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
Tour::mouvementValide(Echiquier & e, int x, int y)
{
  cout << "mouvementValide de Tour" << endl;
  return false;
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
Fou::mouvementValide(Echiquier & e, int x, int y)
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
Cavalier::mouvementValide(Echiquier & e, int x, int y)
{
  cout << "mouvementValide de Cavalier" << endl;
  return false;
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
Pion::mouvementValide(Echiquier & e, int x, int y)
{
  cout << "mouvementValide de Pion" << endl;
  return false;
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


void
Roi::roque(bool left)
{
  cout << "roque " << (left?"gauche":"droit") << " de Roi" << endl;
}

bool
Reine::mouvementValide(Echiquier & e, int x, int y)
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
