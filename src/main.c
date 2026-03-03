/*
 * Автор: Насенник Иван
 * Группа: 12б
 * Лабораторная работа №2
 * Программа для Варианта 17
 */
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 23
#define MAX_PLAYERS 12

struct FOOTBALL
{
		char surname[30];
		int day;
		int month;
		int year;
		char role[30];
		int games;
		int goals;
		char birthplace[30];
};

void sort_desc(int arr[], int size)
{
		int i, j, temp;
		for (i = 0; i < size - 1; i++)
		{
				for (j = i + 1; j < size; j++)
				{
						if (arr[i] < arr[j])
						{
								temp = arr[i];
								arr[i] = arr[j];
								arr[j] = temp;
						}
				}
		}
}

int third_max(int arr[], int size)
{
		sort_desc(arr, size);
		return arr[2];
}

void input_players(struct FOOTBALL players[], int *n)
{
		int i;
		printf("Enter number of players (max 12): ");
		scanf("%d", n);

		if (*n > MAX_PLAYERS)
				*n = MAX_PLAYERS;

		for (i = 0; i < *n; i++)
		{
				printf("\nPlayer %d\n", i + 1);

				printf("Surname: ");
				scanf("%s", players[i].surname);

				printf("Birth day month year: ");
				scanf("%d %d %d", &players[i].day, &players[i].month, &players[i].year);

				printf("Role: ");
				scanf("%s", players[i].role);

				printf("Games: ");
				scanf("%d", &players[i].games);

				printf("Goals: ");
				scanf("%d", &players[i].goals);

				printf("Birthplace: ");
				scanf("%s", players[i].birthplace);
		}
}

int calculate_age(int day, int month, int year)
{
		time_t t = time(NULL);
		struct tm *current = localtime(&t);

		int age = current->tm_year + 1900 - year;

		if ((month > current->tm_mon + 1) ||
				(month == current->tm_mon + 1 && day > current->tm_mday))
		{
				age--;
		}

		return age;
}

void print_effective(struct FOOTBALL players[], int n)
{
		int i;
		printf("\nPlayers older than 20 and >=0.4 goals per game:\n");

		for (i = 0; i < n; i++)
		{
				int age = calculate_age(players[i].day, players[i].month, players[i].year);
				if (age > 20 && players[i].games > 0)
				{
						double ratio = (double)players[i].goals / players[i].games;
						if (ratio >= 0.4)
						{
								printf("%s\n", players[i].surname);
						}
				}
		}
}