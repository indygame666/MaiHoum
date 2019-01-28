// Sortirovka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

int recursia(int *arr, int n)
{
	if (n < 0)
	{
		return 0;  // ошибка
	}
	int max = 0;   //исходное максимальное
	int MAXindex = -1; // его индекс
	for (int i = 0; i < n; i++)  
	{

		if (arr[i] > max) // если текущее > выбранного максимального
		{
			max = arr[i]; // присваеваем
			MAXindex = i; // зависываем индекс

		}

	}

	if (MAXindex != -1)  // после прохождения
	{
		swap(arr[n-1], arr[MAXindex]); // ставим максимальное на последнее место
		recursia(arr, n-1);  // продолжаем без максимального

	}
}

int sliyanie(int *mass, int a, int b)
{
	if (b == a)
		return 0;  // ошибка
	if (b - a == 1) {
		if (mass[b] < mass[a]) 
			swap(mass[b], mass[a]); /// если осталось два элемента, меняем местами
		return 0; 
	}
	int divine = (b + a) / 2;  // пилим массив пополам
	sliyanie(mass, a, divine);  // повторяем процедуру, пока не дойдём до массива с двумя элементами
	sliyanie(mass, divine + 1, b);  // аналогично с второй половиной
	int buffer[sizeof(mass)];  // создаем "буфер" размерность с исходный массив
	int left = a;  
	int right = divine + 1; // будем сравнивать самые левые элементы
	int current = 0; // счетчик текущего положения
	while (b - a + 1 != current)  // пока не выйдем за пределы
	{
		if (left > divine)
			buffer[current++] = mass[right++]; 
		else if (right > b)
			buffer[current++] = mass[left++];
		else if (mass[left] > mass[right]) // сравниваем минимальные элементы двух частей
			buffer[current++] = mass[right++];
		else buffer[current++] = mass[left++];  

	}  
	for (int i = 0; i < current; i++)
		mass[i + a] = buffer[i]; //когда закончили сортировать, заполняем массив
}



void main()
{
	int number;
	
	cout << " Choose number of  integers" << endl;
	cin >> number;
	
	int *newmassiv = new int[number];
	
	for (int i = 0; i < number; i++)
	{   
		cout << "Print the " << i+1 << " integer" << endl;
		cin >> newmassiv[i];
	}
	
	recursia(newmassiv, number);
	
	//sliyanie(arr, 0, number - 1);
	
	for (int i = 0; i < number; i++)
	{
		cout << " " << newmassiv[i];
	}

	getch();

}

