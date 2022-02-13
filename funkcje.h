/**@file*/
#ifndef FUNKCJE_H

#define FUNKCJE_H
#include <stdbool.h>

/**Funkcja sprawdzajaca ile statkow i jakiej wielkosci gracz moze jeszcze ustawic na planszy*/
void rozmiarydostepne(int statki[8]);

/**Funkcja pozwalajaca ustawic graczowi swoje statki na planszy
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza*/
void UstawianieStatkowGracz(char planszaA[10][10]);

/**Funkcja zapisuje wszystkie plansze tak aby po ponownym uruchomieniu programu mozna bylo kontynuowac rozgrywke
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza
@param planszaB tablica dwuwymiarowa pokazujaca proby zestrzelenia statkow przeciwnika
@param planszaC tablica dwuwymiarowa z ustawieniem statkow komputera
@param planszaD tablica dwuwymiarowa z probami komputera zestrzelenia statkow gracza
@param poz poziom trudnosci*/
void zapisz(char planszaA[10][10], char planszaB[10][10], char planszaC[10][10], char planszaD[10][10], char poz);

/*
PlanszaA to plansza gracza
PlanszaB to plansza komputera widoczna dla gracza
PlanszaC to plansza z usatwieniem statkow komputera
PlanszaD to plansza gracza widoczna dla komputera
*/

#endif