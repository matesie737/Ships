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

void zapisz(char planszaA[10][10], char planszaB[10][10], char planszaC[10][10], char planszaD[10][10],char poz)
{
	FILE* save;
	errno_t err;
	err = fopen_s(&save, "save.txt", "w");

	for (int i=0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(save,"%c ", planszaA[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n");
	fprintf(save, "\n");

	for (int i=0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(save, "%c ", planszaB[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n");
	fprintf(save, "\n");

	for (int i=0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(save, "%c ", planszaC[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n");
	fprintf(save, "\n");

	for (int i=0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(save, "%c ", planszaD[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n");
	fprintf(save, "\n");
	fprintf(save, "%c", poz);
	fclose(save);
}

void UstawianieStatkowGracz(char planszaA[10][10])
{
	int statki[8];
	statki[0] = 2;
	statki[1] = 4;
	statki[2] = 3;
	statki[3] = 3;
	statki[4] = 4;
	statki[5] = 2;
	statki[6] = 5;
	statki[7] = 1;
	int iloscstatkow = statki[1] + statki[3] + statki[5] + statki[7];
	printf("%s", "   \n");
	printf("%s", "   \n");
	while (iloscstatkow > 0) {
		planszaGracz(planszaA);

		printf("   	    Dostepne rozmiary statkow: \n");
		printf("%s", "   \n");
		for (int i = 0; i < 8; i = i + 2)
		{
			printf("%s", "	     Rozmiar:  ");
			printf("%i", statki[i]);
			printf("%s", "    Ilosc:  ");
			printf("%i", statki[i + 1]);
			printf("%s", "   \n");
		}
		printf("%s", "   \n");
		printf("   	     Wybierz rozmiar statku: ");
		int rozmiar;
		bool loop = true;
		while (loop)
		{
			scanf_s("%i", &rozmiar);
			for (int i = 0; i < 8; i = i + 2)
			{
				if (statki[i] == rozmiar && statki[i + 1] > 0)
				{
					loop = false;
					statki[i + 1]--;
				}
			}
			if (loop)
				printf("	    Niepoprawny rozmiar! Wprowadz ponownie :  ");
		}
		bool jest = true;
		int mozliwosci[8] = { 0,0,0,0,0,0,0,0 };
		bool tak1 = true;
		bool tak2 = true;
		bool tak3 = true;
		bool tak4 = true;
		int kolpocz;
		int wiepocz;
		int kolkon;
		int wiekon;
		while(jest)
		{
		jest = false;
		planszaGracz(planszaA);
		printf("%s", "   \n");
		printf("%s", "	    Wybrany Rozmiar: ");
		printf("%i%s", rozmiar, "  \n");
		loop = true;
		printf("%s", "   \n");
		printf("%s", "	    Podaj Wspolzedne poczatku statku (1-10)\n");
		while (loop) {
			printf("%s", "	    Kolumna: ");
			scanf_s("%d", &kolpocz);
			printf("%s", "	    Wiersz: ");
			scanf_s("%d", &wiepocz);
			if (planszaA[wiepocz - 1][kolpocz - 1] == '~')
				loop = false;
			else
				printf("%s", "	    Statek jez istnieje w tym miejscu!\n ");
		}
		planszaA[wiepocz - 1][kolpocz - 1] = 207;
		loop = true;
		if (kolpocz + rozmiar - 1 < 10)
		{
			for (int i = 0; i < rozmiar - 1; i++)
			{
				if ((planszaA[wiepocz - 1][kolpocz + i + 1] != 126) && ((kolpocz + i) != 9) || (planszaA[wiepocz - 1][kolpocz + i] != 126) && ((kolpocz + rozmiar - 2) == 9))
				{
					tak1 = false;
				}
				if (((planszaA[wiepocz][kolpocz + i] != 126) && (wiepocz != 10)) || ((planszaA[wiepocz - 2][kolpocz + i] != 126) && (wiepocz - 1 != 0)))
				{
					tak1 = false;
				}
			}
			if (tak1)
			{
				for (int i = 0; i < rozmiar - 1; i++)
				{
					planszaA[wiepocz - 1][kolpocz + i] = 'o';
				}
			}
		}
		if (kolpocz - rozmiar + 1 > 0)
		{
			for (int i = 0; i < rozmiar - 1; i++)
			{
				if (((planszaA[wiepocz - 1][kolpocz - i - 3] != 126) && ((kolpocz - i - 2) != 0)) || ((planszaA[wiepocz - 1][kolpocz - i - 2] != 126) && (kolpocz - rozmiar) == 0))
				{
					tak2 = false;
				}
				if (((planszaA[wiepocz][kolpocz - i - 2] != 126) && (wiepocz != 10)) || ((planszaA[wiepocz - 2][kolpocz - i - 2] != 126) && (wiepocz - 1 != 0)))
				{
					tak2 = false;
				}
			}
			if (tak2)
			{
				for (int i = 0; i < rozmiar - 1; i++)
				{
					planszaA[wiepocz - 1][kolpocz - i - 2] = 'o';
				}
			}
		}
		if (wiepocz + rozmiar - 1 < 10)
		{
			for (int i = 0; i < rozmiar - 1; i++)
			{
				if ((planszaA[wiepocz + i + 1][kolpocz - 1] != 126) && ((wiepocz + i) != 9) || (planszaA[wiepocz + i][kolpocz - 1] != 126) && ((wiepocz + rozmiar - 2) == 9))
				{
					tak3 = false;
				}
				if (((planszaA[wiepocz + i][kolpocz] != 126) && (kolpocz != 10)) || ((planszaA[wiepocz + i][kolpocz - 2] != 126) && (kolpocz - 1 != 0)))
				{
					tak3 = false;
				}
			}
			if (tak3)
			{
				for (int i = 0; i < rozmiar - 1; i++)
				{
					planszaA[wiepocz + i][kolpocz - 1] = 'o';
				}
			}
		}
		if (wiepocz - rozmiar + 1 > 0)
		{
			for (int i = 0; i < rozmiar - 1; i++)
			{
				if (((planszaA[wiepocz - i - 3][kolpocz - 1] != 126) && ((wiepocz - i - 2) != 0)) || ((planszaA[wiepocz - i - 2][kolpocz - 1] != 126) && (wiepocz - rozmiar) == 0))
				{
					tak4 = false;
				}
				if (((planszaA[wiepocz - i - 2][kolpocz] != 126) && (kolpocz != 9)) || ((planszaA[wiepocz - i - 2][kolpocz - 2] != 126) && (kolpocz - 1 != 0)))
				{
					tak4 = false;
				}
			}
			if (tak4)
			{
				for (int i = 0; i < rozmiar - 1; i++)
				{
					planszaA[wiepocz - i - 2][kolpocz - 1] = 'o';
				}
			}
		}
		if ((tak1&& (kolpocz + rozmiar < 11)) || (tak2 && (kolpocz - rozmiar + 1 > 0)) || (tak3 && (wiepocz + rozmiar < 11)) || (tak4 && (wiepocz - rozmiar + 1 > 0)))
		{
			jest = false;
		}
		else
		{
			planszaA[wiepocz - 1][kolpocz - 1] = 126;
			jest = true;
		}
	}
			planszaGracz(planszaA);
			printf("%s", "   \n");
			printf("%s", "	    Podaj Wspolzedne konca statku (1-10)\n");
			printf("%s", "	    Wybrany Rozmiar: ");
			printf("%i%s", rozmiar, "  \n");
			printf("%s", "	    Dostepne Konce statku: ");
				if (tak1&&(kolpocz + rozmiar <11))///prawo
				{
					mozliwosci[0] = wiepocz;
					mozliwosci[1] = kolpocz + rozmiar - 1;
					printf("%i%s%i%s", mozliwosci[1], " x ", mozliwosci[0], "      ");
				}
				if (tak2&&(kolpocz - rozmiar + 1>0))///lewo
				{
					mozliwosci[2] = wiepocz;
					mozliwosci[3] = kolpocz - rozmiar + 1;
					printf("%i%s%i%s", mozliwosci[3], " x ", mozliwosci[2], "      ");
				}
				if (tak3&&(wiepocz + rozmiar <11))///dol
				{
					mozliwosci[4] = wiepocz + rozmiar - 1;
					mozliwosci[5] = kolpocz;
					printf("%i%s%i%s", mozliwosci[5], " x ", mozliwosci[4], "      ");
				}
				if (tak4&&(wiepocz - rozmiar + 1>0))///gora
				{
					mozliwosci[6] = wiepocz - rozmiar + 1;
					mozliwosci[7] = kolpocz;
					printf("%i%s%i%s", mozliwosci[7], " x ", mozliwosci[6], "      ");
				}
			while(loop){
			printf("%s", "   \n");
			printf("%s", "	    Kolumna: ");
			scanf_s("%d", &kolkon);
			printf("%s", "	    Wiersz: ");
			scanf_s("%d", &wiekon);
			if ((kolpocz == kolkon && wiekon - wiepocz == rozmiar - 1) && tak3)///dol
			{
				for (int i = 0; i < rozmiar; i++)
				{
					planszaA[wiepocz + i - 1][kolpocz- 1] = 254;
				}
				loop = false;
			}
			if ((kolpocz == kolkon && wiepocz - wiekon == rozmiar - 1) && tak4)///gora
			{
				for (int i = 0; i < rozmiar; i++)
				{
					planszaA[wiepocz - i - 1][kolpocz - 1] = 254;
				}
				loop = false;
			}
			if ((wiepocz == wiekon && kolpocz - kolkon == rozmiar - 1) && tak2)///lewo
			{
				for (int i = 0; i < rozmiar; i++)
				{
					planszaA[wiepocz-1][kolpocz - i - 1] = 254;
				}
				loop = false;
			}
			if ((wiepocz == wiekon && kolkon - kolpocz == rozmiar - 1)&&tak1)///prawo
			{
				for (int i = 0; i < rozmiar; i++)
				{
					planszaA[wiepocz -1][kolpocz - 1 + i] = 254;
				}
				loop = false;
			}
			if (loop)
			{
				printf("%s", "            Podaj poprawne wspolrzedne!\n");
				Sleep(1500);
				system("cls");
			planszaGracz(planszaA);
			printf("%s", "   \n");
			printf("%s", "	    Podaj Wspolzedne konca statku (1-10)\n");
			printf("%s", "	    Wybrany Rozmiar: ");
			printf("%i%s", rozmiar, "  \n");
			printf("%s", "	    Dostepne Konce statku: ");
				if (tak1&&(kolpocz + rozmiar <11))///prawo
				{
					mozliwosci[0] = wiepocz;
					mozliwosci[1] = kolpocz + rozmiar - 1;
					printf("%i%s%i%s", mozliwosci[1], " x ", mozliwosci[0], "      ");
				}
				if (tak2&&(kolpocz - rozmiar + 1>0))///lewo
				{
					mozliwosci[2] = wiepocz;
					mozliwosci[3] = kolpocz - rozmiar + 1;
					printf("%i%s%i%s", mozliwosci[3], " x ", mozliwosci[2], "      ");
				}
				if (tak3&&(wiepocz + rozmiar <11))///dol
				{
					mozliwosci[4] = wiepocz + rozmiar - 1;
					mozliwosci[5] = kolpocz;
					printf("%i%s%i%s", mozliwosci[5], " x ", mozliwosci[4], "      ");
				}
				if (tak4&&(wiepocz - rozmiar + 1>0))///gora
				{
					mozliwosci[6] = wiepocz - rozmiar + 1;
					mozliwosci[7] = kolpocz;
					printf("%i%s%i%s", mozliwosci[7], " x ", mozliwosci[6], "      ");
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (planszaA[i][j] == 'o')
					planszaA[i][j] = '~';
			}
		}
		iloscstatkow--;
	}
	planszaGracz(planszaA);
	return planszaA;
}

void rozmiarydostepne(int statki[8])
{
	printf("   	    Dostepne rozmiary statkow: \n");
	printf("%s", "   \n");
	for (int i = 0; i < 8; i = i + 2)
	{
		printf("%s", "	     Rozmiar:  ");
		printf("%i", statki[i]);
		printf("%s", "    ilosc:  ");
		printf("%i", statki[i + 1]);
		printf("%s", "   \n");
	}
};
