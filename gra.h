/**@file*/
#ifndef GRA_H
#define GRA_H
#include <stdbool.h>

/**Funkcja kierujacarozgrywka, ustala kto wykonuje ruch i sprawdza kiedy potyczka sie zakonczy
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza
@param planszaB tablica dwuwymiarowa pokazujaca proby zestrzelenia statkow przeciwnika
@param planszaC tablica dwuwymiarowa z ustawieniem statkow komputera
@param planszaD tablica dwuwymiarowa z probami komputera zestrzelenia statkow gracza
@param poz poziom trudnosci
@param ruch okresla czy gracz wykonuje ruch czy komputer
@param pkt okresla ile gracz ma punktow*/
void gra(char planszaA[10][10], char planszaB[10][10], char planszaC[10][10], char planszaD[10][10], bool ruch,char poz, int pkt);


#endif