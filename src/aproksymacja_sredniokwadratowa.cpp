// MN_Aproksymacja_Sredniokwadratowa.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
double wspolczynniki(double*,int,int,int);
double wynik(double*,double*,int,int);


int main()
{
	fstream plik;
	plik.open("mnASrKw.txt",ios::out);

	double x[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 5 };
	double y[] = { -110, -60, -20, -10, -1.5, 2, 7, 18, 50, 170 };

	const int liczbaPunktow = 10;
	const int N = 4; // st wielomianu + 1
	int wspA[N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0)
			{
				int a = wspolczynniki(x, liczbaPunktow, i, j);
				cout << a << "a_" << j;
				plik << a << "a_" << j;
				wspA[j] = a;
			}
			else
			{
				if (j == N-1)
				{
					int a = wspolczynniki(x, liczbaPunktow, i, j);
					cout << a << "a_" << j;
					plik << a << "a_" << j;
					wspA[j] = a;
				}
				else 
				{
					cout << wspA[j+1] << "a_" << j;
					plik << wspA[j + 1] << "a_" << j;
					wspA[j] = wspA[j + 1];
				}
			}

			if (j != N - 1)
			{
				cout << " + ";
				plik << " + ";
			}
			else
			{
				cout << " = " << wynik(x, y, liczbaPunktow, i);
				plik << " = " << wynik(x, y, liczbaPunktow, i);
			}
		}
		if (i != N)
		{
			cout << endl;
			plik <<","<< endl;
		}
	}
	plik.close();
    return 0;
}

double wspolczynniki(double *tabX, int size, int potega1, int potega2)
{
	double wynik = 0;
	for (int i = 0; i < size; i++)
	{
		wynik += pow(tabX[i], potega1)*pow(tabX[i], potega2);
	}
	return wynik;
}
double wynik(double *tabX, double *tabY, int size, int potega)
{
	double wynik = 0;
	for (int i = 0; i < size; i++)
	{
		wynik += pow(tabX[i], potega)*tabY[i];
	}
	return wynik;
}



