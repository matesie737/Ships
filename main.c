/**@file*/
#include <stdio.h>
#include <windows.h>
#include "struktury.h"
#include "wizual.h"
#include "gra.h"
#include "tabwynikow.h"
#include "AI.h"
#include "funkcje.h"
#include <stdbool.h>
#include <conio.h>
#pragma warning(disable : 4996)

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

int main(void)
{
	srand(time(NULL));
	char planszaA[10][10];
	char planszaB[10][10];
	char planszaC[10][10];
	char planszaD[10][10];
	char poz='0';
	int pkt;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			planszaA[i][j] = 126;
			planszaB[i][j] = 126;
			planszaC[i][j] = 126;
			planszaD[i][j] = 126;
		}
	}

	FILE* save;
	errno_t err;
	err = fopen_s(&save, "save.txt", "r");

	if (err==0) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fscanf(save, "%c ", &planszaA[i][j]);
			}
			fscanf(save, "\n");
		}
		fscanf(save, "\n");
		fscanf(save, "\n");

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fscanf(save, "%c ", &planszaB[i][j]);
			}
			fscanf(save, "\n");
		}
		fscanf(save, "\n");
		fscanf(save, "\n");

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fscanf(save, "%c ", &planszaC[i][j]);
			}
			fscanf(save, "\n");
		}
		fscanf(save, "\n");
		fscanf(save, "\n");

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fscanf(save, "%c ", &planszaD[i][j]);
			}
			fscanf(save, "\n");
		}
		fscanf(save, "\n");
		fscanf(save, "%c", &poz);
		fscanf(save, "%c", &pkt);


		fclose(save);
	}
	for(;;)
	{
	char wybor = menupoczatkowe();

	if (wybor == '1')
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				/*if(j==5||j==4||j==3)
				planszaA[i][j] = 254;
				else*/
				planszaA[i][j] = 126;
				planszaB[i][j] = 126;
				planszaC[i][j] = 126;
				planszaD[i][j] = 126;
			}
		}
		for (;;)
		{
			WyborPoziomuTrudnosci();
			poz = _getche();
			if (poz == '1' || poz == '2' || poz == '3')
				break;
		}
		bool ruch = true;
		pkt = 120;
		UstawianieStatkowGracz(planszaA);
		UstawianieStatkowKomputer(planszaC);
		//planszaC[1][1] = 254;
		gra(planszaA,planszaB,planszaC,planszaD, ruch, poz, pkt);
	}
	if (wybor == '2')
	{
		bool ruch = true;
		if (poz != '1' || poz != '2' || poz != '3')
			for (;;)
			{
				WyborPoziomuTrudnosci();
				poz = _getche();
				if (poz == '1' || poz == '2' || poz == '3')
					break;
			}
		gra(planszaA, planszaB, planszaC, planszaD, ruch, poz, pkt);
	}
	if (wybor == '3')
	{
		system("cls");
		piraci* head = NULL;
		wczytajtab(&head);
		wyswietl(head);
		usunliste(&head);
		printf("\n\n\n		Aby wrocic do menu kliknij dowolny przycisk");
		char a;
		a = _getche();
	}
	if (wybor == '4')
	{
		system("cls");

		printf("\n\n				ZASADY GRY:\n\n		gra rozpoczyna sie od ustawienia statkow na planszy\n		gracz oraz komputer maja do dyspozycji 10 statkow:\n		- 1 wielkosci 5 kratek\n		- 2 wielkosci 4 kratki\n		- 3 wielkosci 3 kratki\n		- 4 wielkosci 2 kratki\n		najpierw nalezy wybrac rozmiar statku a nastepnie podac jego polozenie poczatkowe oraz koncowen\n		(ustawienia nie mozna cofnac)\n		gra polega na probie zestrzelenia wszyskich statkow przeciwnika\n		ustawienie statkow przeciwnika jest dla gracza niewidoczne\n		po trafionym strzale mozna wykonac kolejny ruch\n		gra zakonczy sie w momencie kiedy jedna z plansz bedzie pusta\n");

		printf("\n\n\n		Aby wrocic do menu kliknij dowolny przycisk");
		char a;
		a = _getche();
	}
	if (wybor == '5')
	{
		break;
	}
}
	return 0;
}
   