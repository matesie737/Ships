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

void gra(char planszaA[10][10], char planszaB[10][10], char planszaC[10][10], char planszaD[10][10], bool ruch, char poz, int pkt)
{
	int cel1, cel2, trafienie=0;
	int oldcelx1=0, oldcelx2=0, oldcely1=0, oldcely2=0;

	bool rozgrywka = true, wygrales = true;

	while (rozgrywka)
	{
		zapisz(planszaA, planszaB, planszaC, planszaD, poz);
		OknoRozgrywki(planszaA, planszaB, ruch);
		if (ruch)
		{
			printf("   \n");
			printf("   \n");
			printf("   Oddaj strzal!\n");
			printf("   \n");
			bool loop = true;
			while (loop) {
				loop = false;
				printf("   Kolumna:");
				scanf_s("%i", &cel1);
				cel1--;
				printf("   Wiersz:");
				bool p = true;
				while (p) {
					int q = 1;
					while (q == 1)
					{
						q = 0;
						int o;
						o = scanf_s("%i", &cel2);
						if (o == 1)
						{
							p = false;
						}
						else
						{
							scanf_s("%i", &cel2);
						}
					}
				}

				cel2--;
				if (planszaB[cel2][cel1] == 126)
				{
					if (planszaC[cel2][cel1] != 126)
					{
						napisboom();
						planszaB[cel2][cel1] = 'X';
						planszaC[cel2][cel1] = 126;
						int caount = 100;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (planszaC[i][j] == 126)
									caount--;
							}
						}
						if (caount == 0)
						{
							rozgrywka = false;
							wygrales = true;
						}
					}
					else
					{
						planszaB[cel2][cel1] = '0';
						ruch = false;
					}
				}
				else
				{
					system("cls");
					OknoRozgrywki(planszaA, planszaB, ruch);
					printf("   \n");
					printf("   \n");
					printf("	Oddaj prawidlowy strzal w nieodkryte miejsce!\n");
					printf("   \n");
					loop = true;
				}
			}
		}
		else
		{
			Sleep(300);
			ruchkomputer(planszaA, planszaD, poz, &oldcelx1, &oldcelx2, &oldcely1, &oldcely2, &trafienie);
			int caount = 100;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (planszaA[i][j] == 126 || planszaA[i][j] == 'X' || planszaA[i][j] == '0')
						caount--;
				}
			}
			if (caount == 0)
			{
				rozgrywka = false;
				wygrales = false;
			}
			if (trafienie == 0)
				ruch = true;
			else
				ruch = false;
			Sleep(700);
		}
	}
	if (wygrales) 
	{
			system("cls");

			int pkt, en=0, al=0;

			for (int i = 0; i < 10; i++)
			{

				for (int j = 0; j < 10; j++)
				{
					if (planszaA[i][j] == -2)al++;
					if (planszaC[i][j] == -2)en++;
				}
			}

			pkt = al - en;

			double pkt2 = pkt;

			if (poz == '2')
			{
				pkt2 = pkt2 * (1.25);
			}
			else if (poz == '3')
			{
				pkt2 = pkt2 * (1.5);
			}


			
			dodajosobê(pkt2);
	}
	else
	{
		while (!_kbhit())
		{
			system("cls");
			printf("\n\n	No niestety! Porazka!\n\n	Moze nie kazdy nadaje sie na pirata ;/\n\n 	Aby powrocic do menu kliknij dowolny przycisk");
		}
	}
}
