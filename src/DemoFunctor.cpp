//============================================================================
// Name        : DemoResultType.cpp
// Author      : Mario Foos
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CSumar
{
	public:
		int operator()(int a, int b) const
		{
			return a + b;
		}
};

class CAcumular
{
	private:
		int total;
	public:
		CAcumular(int init)
		{
			total = init;
		}

		int operator()(int a)
		{
			total += a;
			return total;
		}
};

class Comparar
{
	private:
		bool asc;
	public:
		Comparar()
		{
			asc = true;
		}
		Comparar(bool asc)
		{
			this->asc = asc;
		}
		bool operator()(int a, int b) const
		{
			return asc ? a < b : a > b;
		}
};

void test1();
void test2();
void test3();

int main()
{
	//test1();
	//test2();
	test3();
}

void test1()
{
	CSumar sumar;
	int resultado = sumar (3, 4); // Se invoca como una función
	std::cout << "Resultado de la suma: " << resultado << std::endl;
}
void test2()
{
	CAcumular acum (10);  // Comienza en 10
	std::cout << "Acumulado: " << acum (5) << endl;   // 15
	std::cout << "Acumulado: " << acum (3) << endl;   // 18
}
void test3()
{
	vector<int> datos = { 4, 1, 3, 1, 2, 9, 6, 9 };

	sort(datos.begin (), datos.end (), Comparar(true));
	cout << "Orden ascendente: " << endl;
	for(int n : datos)
	{
		cout << n << " ";
	}
	cout << endl;

	sort(datos.begin (), datos.end (), Comparar(false));
	cout << "Orden descendente: " << endl;
	for(int n : datos)
	{
		cout << n << " ";
	}
	cout << endl;
}
