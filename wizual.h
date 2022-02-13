/**@file*/
#ifndef WIZUAL_H
#define WIZUAL_H
#include <stdbool.h>

/**Funkcja wyswietlajaca menu glowne*/
char menupoczatkowe();

/**Funkcja kosmetyczna wyswietlajaca plansze gracza podczas ustawiania statkow
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza*/
int planszaGracz(char planszaA[10][10]);

/**Funkcja wyswietla plansze widoczna dla gracza
@param planszaA tablica dwuwymiarowa z ustawieniem statkow gracza
@param planszaB tablica dwuwymiarowa pokazujaca proby zestrzelenia statkow przeciwnika
@param ruch zmienna okreslajaca czy ruch wykonuje gracz czy komputer*/
void OknoRozgrywki(char planszaA[10][10], char planszaB[10][10], bool ruch);

/**Funkcja kosmetyczna wyswietlaajaca duzy napis SHIPS
@param napisnadole okresla co ma byc wyswietlone pod napisem*/
void napisships(int napisnadole);

/**Funkcja kosmetyczna wyswietlajaca napis boom w ramce na ekranie*/
void napisboom();

/**Funkcja pozwalajaca poziom trudnosci*/
void WyborPoziomuTrudnosci();


#endif