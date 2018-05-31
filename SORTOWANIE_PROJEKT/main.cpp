// SORTOWANIE_PROJEKT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "Algorytmy.h"
#include<stdlib.h>
#include <windows.h>

int main()
{
	int size_tab;
	printf("podaj wielkosc tablicy\n");
	scanf_s("%d", &size_tab);

	int i, temp_num = 0;
	int *tab = (int*)malloc(size_tab * sizeof(int));
	int *tab1 = (int*)malloc(size_tab * sizeof(int));
	int *tab2 = (int*)malloc(size_tab * sizeof(int));
	//-------------------------------//
	int *tab3 = (int*)malloc(size_tab * sizeof(int));
	int *tab4 = (int*)malloc(size_tab * sizeof(int));
	int *tab5 = (int*)malloc(size_tab * sizeof(int));



	int max_num = 100, min_num = -100;
	for (int j = 0; j < size_tab; j++)
	{
		temp_num = (rand() % (max_num + 1 - min_num)) + min_num;
		tab[j] = temp_num;
		tab1[j] = temp_num;
		tab2[j] = temp_num;
		tab3[j] = temp_num;
		tab4[j] = temp_num;
		tab5[j] = temp_num;

	}

	//-------------------------------------------------//



	int a, b, counter;

	a = GetTickCount();
	insert_sort(tab, size_tab);	b = GetTickCount();

	counter = b - a;

	printf("czas insertion_sort wyniosl: %d ms\n", counter);

	//------------------------------------------------//

	int a1, b1, counter1;

	a1 = GetTickCount();

	selectionSort(tab1, size_tab);
	b1 = GetTickCount();

	counter1 = b1 - a1;

	printf("czas selection_sort wyniosl: %d ms\n", counter1);

	//-------------------------------------------------//
	int counter2, a2, b2;

	a2 = GetTickCount();
	bubble_sort(tab2, size_tab);
	b2 = GetTickCount();

	counter2 = b2 - a2;
	printf("czas bubble_sort wyniosl: %d ms\n", counter2);

	//--------------------------------------------//

	int counter3, a3, b3;

	a3 = GetTickCount();


	b3 = GetTickCount();


	counter3 = b3 - a3;
	printf("czas shell_sort wyniosl: %d ms\n", counter3);


	// --------------------------------------------- //

	int a4, b4, counter4;


	a4 = GetTickCount();
	quicksort(tab3, 0, 200);
	b4 = GetTickCount();


	counter4 = b4 - a4;



	printf("czas quick_sort wyniosl: %d ms\n", counter4);

	//--------------------------------------//


	int a5, b5, counter5;

	a5 = GetTickCount();

	heapsort(tab5, size_tab);

	b5 = GetTickCount();

	counter5 = b5 - a5;

	printf("czas heap_sort wyniosl: %d ms\n", counter5);

	system("pause");

	return 0;
}


