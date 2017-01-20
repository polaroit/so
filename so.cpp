// so.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "simp_opt.h"
#include <fstream>

using std::cout;
using std::endl;

//Минус интрерфейса
//obj(a, b, eps).y_min - вычисляет
//obj(a, b, eps).x_min - вычисляет снова то, что уже вычислено
//можно добавить объект-хранитель для сохранения в нем предыдущих вычислений
//т.е. после вызова obj(a, b, eps).y_min, вызов obj(a, b, eps).x_min будет
//возвращать данные из объекта хранителя
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const double pi = 3.141593;
	double a = 0, b = pi/4, eps = 0.03;

	std::ofstream out;
	out.open("result.txt");

	simp_opt obj("goldencut");
	out << "Золотое сечение: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " итераций : " << obj.getIter() << endl;
	
	obj.setMethod("pal");
	out << "Пауэлл: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " итераций : " << obj.getIter() << endl;

	obj.setMethod("secant");
	out << "Метод секущих: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " итераций : " << obj.getIter() << endl;

	obj.setMethod("HR");
	out << "Метод Ньютона: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " итераций : " << obj.getIter() << endl;

	out.close();
	std::cin.get();
    return 0;
}

