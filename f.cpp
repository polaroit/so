#include "stdafx.h"
#include "f.h"
#include <cmath>


double f(double x)//функция
{
	return tan(x) - 2 * sin(x);
}

double f_(double x)//1 производная
{
	return (1.0 / (cos(x)*cos(x))) - 2 * cos(x);
}

double f__(double x)//вторая производная
{
	return ((2*sin(x)) / (cos(x)*cos(x)*cos(x))) + 2*sin(x);
}


