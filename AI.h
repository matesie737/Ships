/**@file*/
#ifndef AI_H
#define AI_H
#include <stdbool.h>

/**Funkcja ktora wykonuje ruch komputera w zaleznosci od poziomu trudnosci
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza
@param planszaD tablica dwuwymiarowa z probami komputera zestrzelenia statkow gracza
@param poz poziom trudnosci*/
void ruchkomputer(char planszaA[10][10], char planszaD[10][10], char poz);


/**Funkcja okresla gdzie komputer ustawi swoje statki (w sposob losowy)
@param planszaC tablica dwuwymiarowa z ustawieniem statkow komputera*/
void UstawianieStatkowKomputer(char planszaC[10][10]);


#endif