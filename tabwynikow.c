/**@file*/
#include <stdio.h>
#pragma warning(disable : 4996)
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

void wyswietl(piraci* head) 
{
	int index = 0;
	printf("\n\n		Najlepsi gracze:\n\n");
	while (head && index < 10)
	{

		Sleep(100);
		printf("		%i. nick: %s punkty: %d\n",index+1, head->nazwa, head->wynik);
		index++;

		head = head->next;
	}
}

void usunliste(piraci** head)
{
	while (*head)
	{
		struct piraci* tmp = (*head)->next;
		free((*head)->nazwa);
		free(*head);
		*head = tmp;
	}
}

void dodajWKonkretneMiejsce(piraci** head, int punkty, char* nazwa)
{
	if (*head == NULL)
	{
		*head = (piraci*)malloc(sizeof(piraci));
		(*head)->wynik = punkty;
		(*head)->nazwa = (char*)malloc(strlen(nazwa) + 1);
		(*head)->next = NULL;
		strcpy((*head)->nazwa, nazwa);
	}
	else
	{
		if ((*head)->wynik < punkty)
		{
			piraci* tmp = *head;
			*head = (piraci*)malloc(sizeof(piraci));
			(*head)->wynik = punkty;
			(*head)->nazwa = (char*)malloc(strlen(nazwa) + 1);
			(*head)->next = tmp;
			strcpy((*head)->nazwa, nazwa);
		}
		else
		{
			piraci* tmp = *head;
			while (tmp->next != NULL && tmp->next->wynik > punkty)
				tmp = tmp->next;

			piraci* nastepny = tmp->next;

			tmp->next = (piraci*)malloc(sizeof(piraci));
			tmp->next->wynik = punkty;
			tmp->next->nazwa = (char*)malloc(strlen(nazwa) + 1);
			strcpy(tmp->next->nazwa, nazwa);
			tmp->next->next = nastepny;
		}
	}
}

void dodajosobê(int punkty)
{
	piraci* head = NULL;
	wczytajtab(&head);

	char nazwa[20];

	int miejsce = 1;
	piraci* tmp = head;
	while (tmp && tmp->wynik > punkty)
	{
		miejsce++;
		tmp = tmp->next;
	}

	system("cls");

	printf("%s%i%s", "\n\n\n			Udalo ci sie osiagnac wynik: ", punkty, " pkt!\n\n");

	if (miejsce < 11)
	{
		printf("		Zdobywasz %i miejsce! Gratulacje\n\n		Podaj swoj nick: ", miejsce);

		scanf("%s", nazwa);

		dodajWKonkretneMiejsce(&head, punkty, nazwa);

		printf("\n\n");

		wyswietl(head);

	}
	else
	{
		printf("		Niestety nie udalo ci sie trafic do najlepszej 10 ale proboj dalej!\n\n		Aby kontynuowac kliknij dowolny przycisk");
	}

	zapisztab(head);

	usunliste(&head);

	char a;
	a = _getche();

}

void dodajNaKoniecListyJednokierunkowej(piraci** head, int wynik, char* buf)
{
	if (*head == NULL)
	{
		*head = (piraci*)malloc(sizeof(piraci));
		(*head)->wynik = wynik;
		(*head)->nazwa = (char*)malloc(strlen(buf) + 1);
		(*head)->next = NULL;
		strcpy((*head)->nazwa, buf);
	}
	else
	{
		piraci* tmp = *head;

		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = (piraci*)malloc(sizeof(piraci));
		tmp = tmp->next;
		tmp->wynik = wynik;
		tmp->nazwa = (char*)malloc(strlen(buf) + 1);
		tmp->next = NULL;
		strcpy(tmp->nazwa, buf);
	}
}

void wczytajtab(struct piraci** head)
{
	FILE* f;
	f = fopen("najlepsze.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		exit(1);
	}
	int wyn = 0;
	char buff[20];
	while (fscanf(f, "%s %d", buff, &wyn) > 0)
		dodajNaKoniecListyJednokierunkowej(head, wyn, buff);

	fclose(f);
}

void zapisztab(piraci* head)
{
	FILE* f = fopen("najlepsze.txt", "w");

	if (f == NULL)
	{
		perror("fopen");
		exit(1);
	}

	int index = 0;
	while (head && index < 10)
	{
		fprintf(f, "%s %d\n", head->nazwa, head->wynik);
		index++;

		head = head->next;
	}

	fclose(f);
}
