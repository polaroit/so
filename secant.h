#include "stdafx.h"
#include "Action.h"
#include "f.h"
using std::make_pair;


class Secant : public Action
{
public:
	Secant() = default;

	virtual pair<double, double> operator()(double aa, double bb, double epss)
	{
		a = aa;
		b = bb;
		eps = epss;
		double xk1, xk2, xl = a, xr = b;
		iterations = 0;
		while (true)
		{
			++iterations;
			xk1 = xr - static_cast<double>(f_(xr)) / (f_(xr) - f_(xl)) * (xr - xl);
			if (f_(xk1) < 0)
				xl = xk1;
			else
				xr = xk1;

			xk2 = xr - (static_cast<double>(f_(xr) * (xr - xl))) / (f_(xr) - f_(xl));
			if (f_(xk2) < 0)
				xl = xk2;
			else
				xr = xk2;

			if (abs(xk2 - xk1) < eps)
				break;
		}

		return make_pair(f(xk2), xk2);
	}

	virtual double getCountOfIter() const
	{
		return iterations;
	}

};

