#include "stdafx.h"
#include "Action.h"
#include "f.h"
using std::make_pair;

#include <iostream>

//Õ‹ﬁ“ŒÕ
class HR : public Action
{
public:
	HR() = default;

	virtual pair<double, double> operator()(double aa, double bb, double epss)
	{
		a = aa;
		b = bb;
		eps = epss;
	
		
		iterations = 0;

		double x0 = b, x, x1, _f, __f;
		while (true)
		{
			++iterations;
			
			_f = f_(x0);
			__f = f__(x0);
			
				x1 = x0 - static_cast<double>(_f) / __f;
			
			if (abs(x1 - x0) < eps)
				break;
			else
				x0 = x1;
		}
		x = x1;
		return make_pair(f(x), x);
	}

	virtual double getCountOfIter() const
	{
		return iterations;
	}
};

