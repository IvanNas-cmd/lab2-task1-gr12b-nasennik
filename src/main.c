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