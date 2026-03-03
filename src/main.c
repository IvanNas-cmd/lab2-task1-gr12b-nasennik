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

void print_city(struct FOOTBALL players[], int n)
{
		int i;
		printf("\nPlayers born in Brest or Minsk:\n");

		for (i = 0; i < n; i++)
		{
				if (strcmp(players[i].birthplace, "Brest") == 0 ||
						strcmp(players[i].birthplace, "Minsk") == 0)
				{
						printf("%s\n", players[i].surname);
				}
		}
}

void print_youngest(struct FOOTBALL players[], int n)
{
		int i, index = 0;

		for (i = 1; i < n; i++)
		{
				if (players[i].year > players[index].year)
						index = i;
		}

		printf("\nYoungest player: %s\n", players[index].surname);
}

int days_until_birthday(int day, int month)
{
		time_t t = time(NULL);
		struct tm *current = localtime(&t);

		int current_day = current->tm_mday;
		int current_month = current->tm_mon + 1;

		int days = (month - current_month) * 30 + (day - current_day);

		if (days < 0)
				days += 365;

		return days;
}

void print_nearest_birthday(struct FOOTBALL players[], int n)
{
		int i, index = 0;
		int min_days = days_until_birthday(players[0].day, players[0].month);

		for (i = 1; i < n; i++)
		{
				int d = days_until_birthday(players[i].day, players[i].month);
				if (d < min_days)
				{
						min_days = d;
						index = i;
				}
		}

		printf("\nNearest birthday: %s\n", players[index].surname);
}

int main()
{
		int class1[SIZE];
		int class2[SIZE];
		int i;

		printf("Enter heights for class 1:\n");
		for (i = 0; i < SIZE; i++)
				scanf("%d", &class1[i]);

		printf("Enter heights for class 2:\n");
		for (i = 0; i < SIZE; i++)
				scanf("%d", &class2[i]);

		int third1 = third_max(class1, SIZE);
		int third2 = third_max(class2, SIZE);

		printf("\nThird tallest in class 1: %d\n", third1);
		printf("Third tallest in class 2: %d\n", third2);

		if (third1 > third2)
				printf("Class 1 has taller third student\n");
		else if (third2 > third1)
				printf("Class 2 has taller third student\n");
		else
				printf("They are equal\n");

		struct FOOTBALL players[MAX_PLAYERS];
		int n;

		input_players(players, &n);

		print_effective(players, n);
		print_city(players, n);
		print_youngest(players, n);
		print_nearest_birthday(players, n);

		return 0;
}