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