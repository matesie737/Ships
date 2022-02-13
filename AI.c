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

void UstawianieStatkowKomputer(char planszaC[10][10])
{
int D, g;
for (g = 0; g < 10; g++)
{
	if (g == 0)
	{
		D = 5;
	}
	else if ((g == 1) || (g == 2))
	{
		D = 4;
	}
	else if ((g == 3 )|| (g == 4) || (g == 5))
	{
		D = 3;
	}
	else
	{
		D = 2;
	}
	int x;
	int y;
	bool loop = true;
	while (loop) {
		loop = false;
		x = (rand() % 10);
		y = (rand() % 10);
		if (planszaC[x][y] == 126)
		{
			if ((planszaC[x + 1][y] == 126 || (x == 9)) && (planszaC[x][y + 1] == 126 || (y == 9)) && (planszaC[x - 1][y] == 126 || (x == 0)) && (planszaC[x][y - 1] == 126 || (y == 0)))
			{

				int k = (rand() % 4) + 1; ///losowy kierunek
				
					if (k == 1) //gora
					{
						if (x - D + 1 < 0)
						{
							loop = true;
						}
						if (x >= D)
						{
							if (planszaC[x - D][y] != 126)
							{
								loop = true;
							}
						}
						for (int z = 0; z < D; z++)
						{
							if ((planszaC[x - z][y + 1] != 126 && (y != 9)) || (planszaC[x - z][y - 1] != 126 && (y != 0)))
							{
								loop = true;
							}
							if (planszaC[x - z][y] != 126)
							{
								loop = true;
							}
						}
						if (loop == false)
						{
							for (int p = 0; p < D; p++)
							{
								planszaC[x - p][y] = 254;
							}

						}
					}

					if (k == 2) //dol
					{
						if (x + D - 1 > 9)
						{
							loop = true;
						}
						if (x <= 9 - D)
						{
							if (planszaC[x + D][y] != 126)
							{
								loop = true;
							}
						}
						for (int z = 0; z < D; z++)
						{
							if ((planszaC[x + z][y + 1] != 126 && (y != 9)) || (planszaC[x + z][y - 1] != 126 && (y != 0)))
							{
								loop = true;
							}
							if (planszaC[x + z][y] != 126)
							{
								loop = true;
							}
						}
						if (loop == false)
						{
							for (int z = 0; z < D; z++)
							{
								planszaC[x + z][y] = 254;
							}

						}
					}

					if (k == 3) //lewo
					{
						if (y - D + 1 < 0)
						{
							loop = true;
						}
						if (y >= D)
						{
							if (planszaC[x][y - D] != 126)
							{
								loop = true;
							}
						}
						for (int z = 0; z < D; z++)
						{
							if ((planszaC[x + 1][y - z] != 126 && (x != 9)) || (planszaC[x - 1][y - z] != 126 && (x != 0)))
							{
								loop = true;
							}
							if (planszaC[x][y - z] != 126)
							{
								loop = true;
							}
						}
						if (loop == false)
						{
							for (int z = 0; z < D; z++)
							{
								planszaC[x][y - z] = 254;
							}

						}
					}

					if (k == 4) //prawo
					{
						if (y + D - 1 > 9)
						{
							loop = true;
						}
						if (y <= 9 - D)
						{
							if (planszaC[x][y + D] != 126)
							{
								loop = true;
							}
						}
						for (int z = 0; z < D; z++)
						{
							if ((planszaC[x + 1][y + z] != 126 && (x != 9)) || (planszaC[x - 1][y + z] != 126 && (x != 0)))
							{
								loop = true;
							}
							if (planszaC[x][y + z] != 126)
							{
								loop = true;
							}
						}
						if (loop == false)
						{
							for (int z = 0; z < D; z++)
							{
								planszaC[x][y + z] = 254;
							}

						}
					}
				}
			else
				loop = true;
		}
		else
		{
			loop = true;
		}
	}
}
}

void ruchkomputer(char planszaA[10][10], char planszaD[10][10], char poz, int* oldcelx1, int* oldcelx2, int* oldcely1, int* oldcely2, int* trafienie)
{
	if (poz == '1')
	{
		int cel1, cel2;
		bool loop = true;
		while (loop)
		{
			loop = false;
			cel1 = rand() % 10;
			cel2 = rand() % 10;
			if (planszaD[cel1][cel2] == 126)
			{
				if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
				{
					planszaA[cel1][cel2] = 'X';
					planszaD[cel1][cel2] = 'X';
				}
				else
				{
					planszaA[cel1][cel2] = '0';
					planszaD[cel1][cel2] = '0';
				}
			}
			else
			{
				loop = true;
			}
		}
	}
	if (poz == '2')//Sredni na jeza taki o
	{
		int cel1, cel2;
		bool loop = true;
		while (loop)
		{
			loop = false;
			cel1 = rand() % 10;
			cel2 = rand() % 10;
			//////////////////////////////
			if (*trafienie == 1)
			{
				bool loop2 = true;
				bool all1 = false, all2 = false, all3 = false, all4 = false;
				while (loop2 && (!all1 || !all2 || !all3 || !all4))
				{
					loop2 = false;
					int kie;
					kie = (rand() % 4);
					if (kie == 0 && !all1) //góra
					{
						if ((*oldcelx1) < 9) //trafi³
						{
							if (planszaD[*oldcelx1 + 1][*oldcely1] == 126)
							{

								cel1 = (*oldcelx1) + 1;
								cel2 = *oldcely1;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
									(*oldcelx1) = cel1;
									*oldcely1 = cel2;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all1 = true;
							}
						}
						else {
							loop2 = true;
							all1 = true;
						}
					}
					if (kie == 1 && !all2) //dó³
					{
						if ((*oldcelx1) > 0)
						{
							if (planszaD[(*oldcelx1) - 1][*oldcely1] == 126)
							{

								cel1 = (*oldcelx1) - 1;
								cel2 = *oldcely1;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
									(*oldcelx1) = cel1;
									*oldcely1 = cel2;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all2 = true;
							}
						}
						else {
							loop2 = true;
							all2 = true;
						}
					}
					if (kie == 2 && !all3) //prawo
					{
						if (*oldcely1 > 0)
						{
							if (planszaD[(*oldcelx1)][*oldcely1 + 1] == 126)
							{

								cel1 = (*oldcelx1);
								cel2 = *oldcely1 + 1;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
									(*oldcelx1) = cel1;
									*oldcely1 = cel2;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all3 = true;
							}
						}
						else {
							loop2 = true;
							all3 = true;
						}
					}
					if (kie == 3 && !all4) //lewo 
					{
						if (*oldcely1 < 9)
						{
							if (planszaD[(*oldcelx1)][*oldcely1 - 1] == 126)
							{

								cel1 = (*oldcelx1);
								cel2 = *oldcely1 - 1;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									*trafienie = 1;
									(*oldcelx1) = cel1;
									*oldcely1 = cel2;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all4 = true;
							}
						}
						else {
							loop2 = true;
							all4 = true;
						}
					}
					if (all1 && all2 && all3 && all4)
						(*trafienie) = 0;

				}
			}
			else
			{
				if (planszaD[cel1][cel2] == 126)
				{
					if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
					{
						planszaA[cel1][cel2] = 'X';
						planszaD[cel1][cel2] = 'X';
						(*trafienie) = 1;
						(*oldcelx1) = cel1;
						*oldcely1 = cel2;
					}
					else
					{
						planszaA[cel1][cel2] = '0';
						planszaD[cel1][cel2] = '0';
						(*trafienie) = 0;
					}
				}
				else
				{
					loop = true;
				}
			}
		}
	}
	if (poz == '3')//PIEKIELNYYYYYYYYYYYYY
	{
		int cel1, cel2;
		bool loop = true;
		while (loop)
		{
			loop = false;
			cel1 = rand() % 10;
			cel2 = rand() % 10;
			//////////////////////////////
			if ((*trafienie) == 1)
			{
				bool loop2 = true;
				bool all1 = false, all2 = false, all3 = false, all4 = false;
				while (loop2 && (!all1 || !all2 || !all3 || !all4))
				{
					loop2 = false;
					int kie;
					kie = (rand() % 4);
					if (kie == 0 && !all1) //góra
					{
						if ((*oldcelx1) < 9) //trafi³
						{
							if (planszaD[(*oldcelx1) + 1][*oldcely1] == 126)
							{

								cel1 = (*oldcelx1) + 1;
								cel2 = oldcely1;
								(*oldcelx1) = cel1;
								oldcely1 = cel2;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all1 = true;
							}
						}
						else {
							loop2 = true;
							all1 = true;
						}
					}
					if (kie == 1 && !all2) //dó³
					{
						if ((*oldcelx1) > 0)
						{
							if (planszaD[(*oldcelx1) - 1][(*oldcely1)] == 126)
							{

								cel1 = (*oldcelx1) - 1;
								cel2 = oldcely1;
								(*oldcelx1) = cel1;
								*oldcely1 = cel2;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all2 = true;
							}
						}
						else {
							loop2 = true;
							all2 = true;
						}
					}
					if (kie == 2 && !all3) //prawo
					{
						if (*oldcely1 > 0)
						{
							if (planszaD[(*oldcelx1)][*oldcely1 + 1] == 126)
							{

								cel1 = (*oldcelx1);
								cel2 = oldcely1 + 1;
								(*oldcelx1) = cel1;
								*oldcely1 = cel2;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all3 = true;
							}
						}
						else {
							loop2 = true;
							all3 = true;
						}
					}
					if (kie == 3 && !all4) //lewo 
					{
						if (*oldcely1 < 9)
						{
							if (planszaD[(*oldcelx1)][*oldcely1 - 1] == 126)
							{

								cel1 = (*oldcelx1);
								cel2 = oldcely1 - 1;
								(*oldcelx1) = cel1;
								*oldcely1 = cel2;

								if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
								{
									planszaA[cel1][cel2] = 'X';
									planszaD[cel1][cel2] = 'X';
									(*trafienie) = 1;
								}
								else
								{
									planszaA[cel1][cel2] = '0';
									planszaD[cel1][cel2] = '0';
									(*trafienie) = 0;
								}
							}
							else {
								loop2 = true;
								all4 = true;
							}
						}
						else {
							loop2 = true;
							all4 = true;
						}
					}
					if (all1 && all2 && all3 && all4)
						(*trafienie) = 0;
				}
			}
			else
			{
				bool loop3 = true;
				while (loop3) {
					loop3 = false;
					if (planszaD[cel1][cel2] == 126)
					{
						if (planszaA[cel1][cel2] != 126 && planszaA[cel1][cel2] != '0' && planszaA[cel1][cel2] != 'X')
						{
							planszaA[cel1][cel2] = 'X';
							planszaD[cel1][cel2] = 'X';
							(*trafienie) = 1;
							(*oldcelx1) = cel1;
							*oldcely1 = cel2;
						}
						else
						{
							int szan = (rand() % 2);
							if (szan == 0) {
								loop = true;
								cel1 = rand() % 10;
								cel2 = rand() % 10;
							}
							else {
								planszaA[cel1][cel2] = '0';
								planszaD[cel1][cel2] = '0';
								(*trafienie) = 0;
							}
						}
					}
					else
					{
						loop = true;
					}
				}
				(*oldcelx1) = cel1;
				*oldcely1 = cel2;
			}
		}
	}
}