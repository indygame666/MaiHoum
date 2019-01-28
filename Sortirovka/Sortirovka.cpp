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
		return 0;  // ������
	}
	int max = 0;   //�������� ������������
	int MAXindex = -1; // ��� ������
	for (int i = 0; i < n; i++)  
	{

		if (arr[i] > max) // ���� ������� > ���������� �������������
		{
			max = arr[i]; // �����������
			MAXindex = i; // ���������� ������

		}

	}

	if (MAXindex != -1)  // ����� �����������
	{
		swap(arr[n-1], arr[MAXindex]); // ������ ������������ �� ��������� �����
		recursia(arr, n-1);  // ���������� ��� �������������

	}
}

int sliyanie(int *mass, int a, int b)
{
	if (b == a)
		return 0;  // ������
	if (b - a == 1) {
		if (mass[b] < mass[a]) 
			swap(mass[b], mass[a]); /// ���� �������� ��� ��������, ������ �������
		return 0; 
	}
	int divine = (b + a) / 2;  // ����� ������ �������
	sliyanie(mass, a, divine);  // ��������� ���������, ���� �� ����� �� ������� � ����� ����������
	sliyanie(mass, divine + 1, b);  // ���������� � ������ ���������
	int buffer[sizeof(mass)];  // ������� "�����" ����������� � �������� ������
	int left = a;  
	int right = divine + 1; // ����� ���������� ����� ����� ��������
	int current = 0; // ������� �������� ���������
	while (b - a + 1 != current)  // ���� �� ������ �� �������
	{
		if (left > divine)
			buffer[current++] = mass[right++]; 
		else if (right > b)
			buffer[current++] = mass[left++];
		else if (mass[left] > mass[right]) // ���������� ����������� �������� ���� ������
			buffer[current++] = mass[right++];
		else buffer[current++] = mass[left++];  

	}  
	for (int i = 0; i < current; i++)
		mass[i + a] = buffer[i]; //����� ��������� �����������, ��������� ������
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

