/**@file*/
#ifndef TABWYNIKOW_H
#define TABWYNIKOW_H
#include <stdbool.h>

/**Funkcja wyswietla liste najlepszych wynikow
@param head wskaznik na pierwszego gracza*/
void wyswietl(struct piraci* head);

/**Funkcja usuwa wszystkie wskazniki
@param head wskaznik na pierwszego gracza*/  
void usunliste(struct piraci* head);

/**Funkcja zapisuje tablice wynikow w pliku
@param head wskaznik na pierwszego gracza*/
void zapisztab(struct piraci* head);

/**Funkcja czyta z pliku tablice wynikow
@param head wskaznik na pierwszego gracza*/
void wczytajtab(struct piraci* head);


/**Funkcja dodaje nowego gracza w konkretne miejsce listy wynikow
@param head wskaznik na pierwszego gracza
@param punkty liczbba punktow zdobytych przez gracza
@param nazwa pseudnik gracza ktory sam wybral*/
void dodajWKonkretneMiejsce(struct piraci* head, int punkty, char* nazwa);

/**Funkcja czyta z pliku tablice wynikow
@param head wskaznik na pierwszego gracza
@param wynik liczbba punktow zdobytych przez gracza
@param buf nazwa gracza*/
void dodajNaKoniecListyJednokierunkowej(struct piraci* head, int wynik, char* buf);

/**Funkcja dodaje nowego gracza do listy wynikow jesli jego wynik na to pozwala
@param punkty liczba punktow zdobytych przez gracza, ktora okresla na gtorym miejscu sie znajduje*/
void dodajosobê(int punkty);

#endif