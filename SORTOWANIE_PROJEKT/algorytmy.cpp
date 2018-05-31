#include "Algorytmy.h"
#include "stdafx.h"
#include <iostream>

using namespace std;

void insert_sort(int *tab, int n)
{
	int i, x, j;
	for (i = 1; i<n;i++)
	{
		x = tab[i];
		j = i - 1;
		while (tab[j]>x && j >= 0)
		{
			tab[j + 1] = tab[j]; j--;
		}
		tab[j + 1] = x;
	}
}void bubble_sort(int * a, int n)
{
	int i, j, pom, zamiana = 1;
	for (j = 0; j < n - 1 && zamiana; j++)
	{
		zamiana = 0;
		for (i = n - 2;i >= j;i--)
			if (a[i]>a[i + 1])
			{
				pom = a[i];
				a[i] = a[i + 1];
				a[i + 1] = pom;
				zamiana = 1;
			};
	}
}//---------------------------------------------------//void swap1(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap1(&arr[min_idx], &arr[i]);
	}
}//void selection_sort(int *tab, int N, int *i_max, int *max)
//{
	//int z;
	//*max = tab[N];
	//*i_max = N;
	//for (z = N + 1; z < 10; z++)
	//{
		//if (tab[z] > *max)
		//{
		//	*max = tab[z]; *i_max = z;
		//}
//	}
//}

void quicksort(int *a, int p, int k)
{
	int i = p, j = k, s, pom
		;
	s = a[(i + j) / 2];
	do
	{
		while (a[i]<s)
			i++;
		while (a[j]>s)

			j--
			;
		if
			(i <= j
				)
		{
			pom = a[i]; a[i] = a[j]; a[j] = pom; i++; j--;
		};

	} while
		(i <= j);
	if
		(j>p) quicksort
		(a, p, j);
	if
		(i<k) quicksort
		(a, i, k);

}

void swap(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void shell_sort_insert(int tab[], int imax, int h)
{

	int x;
	int n, i, j;
	for (n = 0; n<h; n++)
	{
		for (i = n + h; i<imax; i += h)
		{
			cout << "i=" << i << "tab[i]=" << tab[i] << endl;
			for (j = i - h; j >= 0 && tab[j]>tab[j + h]; j -= h)
				std::swap(tab[j + h], tab[j]);
		}
	}
}

void shell_sort(int tab[], int max) {
	//Szukanie pocz¹tkowego "skoku" dla przedzia³u
	int hn = 1, h = 1;
	do
	{
		h = hn;
		hn = h * 3 + 1;
	} while (hn <= max);
	cout << "shell_sort >>> h=" << h << endl;
	//Sortujemy z coraz mniejszymi przedzia³ami dopóki s¹ wiêksze ni¿ 0
	while (h>0)
	{
		shell_sort_insert(tab, max, h);
		cout << endl << "h=" << h << endl;
		for (int i = 0;i<max;i++)
			cout << tab[i] << endl;
		h /= 3;
	}
}





//tutaj stogowe

void max_heapify(int *a, int i, int n)
{
	int largest;
	int l = 2 * i;
	int r = l + 1;
	if (l <= n && a[l]>a[i])
		largest = l;
	else
		largest = i;

	if (r <= n && a[r]>a[largest])
		largest = r;
	if (largest != i)
	{
		std::swap(a[i], a[largest]);
		max_heapify(a, largest, n);
	}
}

void build_max_heap(int *a, int n)
{
	int i;
	for (i = n / 2;i>0;i--)
		max_heapify(a, i, n);
}void heapsort(int *a, int n)
{
	build_max_heap(a, n);
	for (int i = n;i >= 2;i--)
	{
		std::swap(a[1], a[i]);
		n--;
		max_heapify(a, 1, n);
	}
}