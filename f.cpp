#include "stdafx.h"
#include "f.h"
#include <cmath>


double f(double x)//�������
{
	return tan(x) - 2 * sin(x);
}

double f_(double x)//1 �����������
{
	return (1.0 / (cos(x)*cos(x))) - 2 * cos(x);
}

double f__(double x)//������ �����������
{
	return ((2*sin(x)) / (cos(x)*cos(x)*cos(x))) + 2*sin(x);
}


