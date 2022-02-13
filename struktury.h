/**@file*/
#ifndef STRUKTURY_H

#define STRUKTURY_H
/**Struktura przechowuj¹ca informacje o graczach
@param wynik liczba punktow uzyskana przez gracza
@param nazwa pseudonim gracza
@param next wskaznik na nastepnego gracza
@param prev wskaznik na poprzedniego gracza*/
typedef struct Piraci {
	
	int wynik;

	char* nazwa;

	struct Piraci* next;

	struct Piraci* prev;

} piraci;


#endif