#include "stdafx.h"
#include "simp_opt.h"
#include "goldencut.h"
#include "Pal.h"
#include "Secant.h"
#include "HR.h"


simp_opt::simp_opt(const string &n)
	:op(nullptr)
{
	setMethod(n);
}

simp_opt::~simp_opt()
{
	delete op;
}

simp_opt::min_point simp_opt::operator()(double aa, double bb, double epss)
{
	return point = op->operator()(aa, bb, epss);
}

void simp_opt::setMethod(const string &n)
{
	if (n == "goldencut")
	{
		delete op;
		op = new GoldenCut();
	}

	if (n == "pal")
	{
		delete op;
		op = new Pal();
	}

	if (n == "HR")
	{
		delete op;
		op = new HR();
	}

	if (n == "secant")
	{
		delete op;
		op = new Secant();
	}

}

double simp_opt::getIter() const
{
	return op->getCountOfIter();
}
