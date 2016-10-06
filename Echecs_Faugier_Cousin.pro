#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T17:07:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Echecs_Faugier_Cousin
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Piece.cxx \
    Joueur.cxx \
    Echiquier.cxx \
    testPiece.cxx \
    GameModel.cxx \
    GameView.cxx

HEADERS += \
    Piece.h \
    Joueur.h \
    Echiquier.h \
    GameModel.h \
    GameView.h
