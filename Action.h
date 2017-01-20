#include "stdafx.h"
#include <utility>
using std::pair;


#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
	Action() = default;
	
	virtual ~Action()
	{};
	virtual pair<double, double> operator()(double, double, double) = 0;

	virtual double getCountOfIter() const = 0;
	
	
protected:
	double a;
	double b;
	double eps;
	int iterations;
};


#endif
