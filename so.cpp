// so.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "simp_opt.h"
#include <fstream>

using std::cout;
using std::endl;

//����� �����������
//obj(a, b, eps).y_min - ���������
//obj(a, b, eps).x_min - ��������� ����� ��, ��� ��� ���������
//����� �������� ������-��������� ��� ���������� � ��� ���������� ����������
//�.�. ����� ������ obj(a, b, eps).y_min, ����� obj(a, b, eps).x_min �����
//���������� ������ �� ������� ���������
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const double pi = 3.141593;
	double a = 0, b = pi/4, eps = 0.03;

	std::ofstream out;
	out.open("result.txt");

	simp_opt obj("goldencut");
	out << "������� �������: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " �������� : " << obj.getIter() << endl;
	
	obj.setMethod("pal");
	out << "������: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " �������� : " << obj.getIter() << endl;

	obj.setMethod("secant");
	out << "����� �������: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " �������� : " << obj.getIter() << endl;

	obj.setMethod("HR");
	out << "����� �������: " << endl;
	out << "y_min = " << obj(a, b, eps).y_min << "   " << "x_min = " << obj(a, b, eps).x_min;
	out << " �������� : " << obj.getIter() << endl;

	out.close();
	std::cin.get();
    return 0;
}

