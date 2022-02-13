/**@file*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "struktury.h"
#include "wizual.h"
#include "gra.h"
#include "tabwynikow.h"
#include "AI.h"
#include "funkcje.h"
#include <stdbool.h>
#include <conio.h>

void WyborPoziomuTrudnosci()
{
	int czas = 0;
	while (!_kbhit())
	{
		if (czas > 48)
			czas = 0;
		system("cls");
		printf("%s", "\n\n	A wiec zdecydowales sie na nowa potyczke tak? Wybierz poziom trudnosci!\n\n");
		for (int i = 0; i < czas - 35; i++)
		{
			printf("%s", "	");
		}
		if (czas > 35)
		{
			if (czas % 2 == 0)
				printf("%s%c%c", "/", 94, 92);
			else
				printf("%c%c%s", 92, 94, "/");

		}
		printf("%s", "\n\n	1. Majtek(latwy)\n	2. Zeglarz(sredni)\n	3. Kapitan(trudny)\n	");
		Sleep(500);
		czas++;
	}
}

void napisships(int napisnadole)
{


	int zn = 0;
	char zn2 = 207, zn3 = 254, l;
	while (!_kbhit())
	{
		if (zn == 0) { l = zn2; zn = 1; }
		else { l = zn3; zn = 0; }
		system("cls");
		printf("%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s", "\n\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%                                                          %%%%%\n	%%%%%    ", l, l, " ", l, l, " ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, " ", l, l, " ", l, l, "    ", l, l, " ", l, l, " ", l, l, "    %%%%%\n	%%%%%    ", l, l, "          ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "          %%%%%\n	%%%%%    ", l, l, " ", l, l, " ", l, l, "    ", l, l, " ", l, l, " ", l, l, "    ", l, l, "    ", l, l, " ", l, l, " ", l, l, "    ", l, l, " ", l, l, " ", l, l, "    %%%%%\n	%%%%%          ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "                ", l, l, "    %%%%%\n	%%%%%    ", l, l, " ", l, l, " ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "    ", l, l, "          ", l, l, " ", l, l, " ", l, l, "    %%%%%\n	%%%%%                                                          %%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Mateusz Siedlaczek %%%%%%%%%\n");
		if (napisnadole == 1)
		{
			printf("%s", "\n	Witaj Piracie! Arrrrr!\n\n	Aby rozpoczac przygode wcisnij dowolny klawisz\n	\b \b");
		}
		if (napisnadole == 2)
		{
			printf("%s", "\n	Wybierz co Zamierzasz(wybierz numerek):\n\n	1. Rozpoczac Nowa Potyczke!\n	2. Kontynuowac bitwe morska\n	3. Zobaczyc Liste najdzielniejszych piratow\n	4. Wyswietlic Zasady gry\n	5. Wyjsc z gry\n	");
		}
		Sleep(1000);
	}
}

char menupoczatkowe()
{


	char cel;
	char a;
	napisships(1);
	a = _getche();
	for (;;)
	{
		napisships(2);
		cel = _getche();
		if ((cel == '1') || (cel == '2') || (cel == '3') || (cel == '4') || (cel == '5'))
			break;
	}
	return cel;
}

void napisboom()
{
	int l = 1;
	char z;
	for (int i = 0; i < 6; i++) {
		if (l == 1) { z = 207, l = 0; }
		else { z = 254; l = 1; }
		system("cls");
		printf("%s", "\n\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%                                                         %%%%%\n");
		printf("%s", "	%%%%%    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "        "); printf("%c%c", z, z); printf(" % s", "    %%%%%\n");
		printf("%s", "	%%%%%    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z);  printf("%s", " "); printf("%c%c", z, z); printf("%s", "  "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z);                       printf(" % s", "    %%%%%\n");
		printf("%s", "	%%%%%    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "   "); printf("%c%c", z, z); printf("%s", "   "); printf("%c%c", z, z); printf(" % s", "    %%%%%\n");
		printf("%s", "	%%%%%    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "        "); printf("%c%c", z, z);                       printf(" % s", "    %%%%%\n");
		printf("%s", "	%%%%%    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", " "); printf("%c%c", z, z); printf("%s", "    "); printf("%c%c", z, z); printf("%s", "        "); printf("%c%c", z, z); printf(" % s", "    %%%%%\n");
		printf("%s", "	%%%%%                                                         %%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n				Trafiony!\n\n			       	");
		Sleep(200);
	}
}

int  planszaGracz(char planszaA[10][10]) {

	system("cls");
	printf("%s", " \n");
	printf("%s", "                1 2 3 4 5 6 7 8 9 10\n");
	printf("%s", " \n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%             Na Poczatku Zajmijmy sie rozmieszczeniem twoich okretow!\n");
	printf("%s", "         %%%%                         %%%%");
	for (int i = 0; i < 10; i++)
	{
		printf("%s", "\n    ");
		if (i < 9)
		{
			printf("%c", 49 + i);
			printf("%s", "    %%%%   ");
		}
		else
		{
			printf("%c", 49);
			printf("%c", 48);
			printf("%s", "   %%%%   ");
		}
		for (int j = 0; j < 10; j++)
		{
			printf("%c%s", planszaA[i][j], " ");
		}
		printf("%s", "  %%%%");
		if (i == 1)
			printf("    Legenda:");
		if (i == 3)
			printf("    ~ - wolne miejsce");
		if (i == 4)
		{
			printf("    ");
			printf("%c", 207);
			printf(" - poczatek ustawianego statku");
		}
		if (i == 5)
			printf("    o - dostepne kierunki oraz pogladowe ulozenie");
		if (i == 6)
		{
			printf("    ");
			printf("%c", 254);
			printf(" - Twoj statek");
		}
	}
	printf("%s", "\n         %%%%                         %%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%s", "   \n");
}

void OknoRozgrywki(char planszaA[10][10], char planszaB[10][10], bool ruch)
{
	system("cls");
	printf("%s", " \n");
	printf("%s", " \n");
	printf("%s", "                   Twoja Plansza                                  Komputer            \n");
	printf("%s", " \n");
	printf("%s", "                1 2 3 4 5 6 7 8 9 10                        1 2 3 4 5 6 7 8 9 10      \n");
	printf("%s", " \n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%       Ruch wykonuje: "); if (ruch) printf("%s", "Gracz\n"); else printf("%s", "Komputer\n");
	printf("%s", "         %%%%                         %%%%           %%%%                         %%%%");
	for (int i = 0; i < 10; i++)
	{
		printf("%s", "\n    ");
		if (i < 9)
		{
			printf("%c", 49 + i);
			printf("%s", "    %%%%   ");
		}
		else
		{
			printf("%c", 49);
			printf("%c", 48);
			printf("%s", "   %%%%   ");
		}
		for (int j = 0; j < 10; j++)
		{
			printf("%c%s", planszaA[i][j], " ");
		}
		printf("%s", "  %%%%      ");
		if (i < 9)
		{
			printf("%c", 49 + i);
			printf("%s", "    %%%%   ");
		}
		else
		{
			printf("%c", 49);
			printf("%c", 48);
			printf("%s", "   %%%%   ");
		}
		for (int j = 0; j < 10; j++)
		{
			printf("%c%s", planszaB[i][j], " ");
		}
		printf("%s", "  %%%%   ");
		if (i == 1)
			printf("    Legenda:");
		if (i == 3)
			printf("    ~ - nieodkryte miejsce");
		if (i == 4)
			printf("    X - trafiony statek");
		if (i == 5)
		{
			printf("    ");
			printf("%c", 254);
			printf(" - Twoj statek");
		}
		if (i == 6)
			printf("    0 - puste miejsce");
	}
	printf("%s", "\n         %%%%                         %%%%           %%%%                         %%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%s", "         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}
