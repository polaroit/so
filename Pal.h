#include "stdafx.h"
#include "Action.h"
#include "f.h"
#include <algorithm>
using std::make_pair;
using std::min;

//œ¿”›ÀÀ
class Pal : public Action
{
public:
	Pal() = default;

	virtual pair<double, double> operator()(double aa, double bb, double epss)
	{

		a = aa;
		b = bb;
		eps = epss;

		double tau = 2, a1, a2;


		double delta = static_cast<double>(b - a) / tau;
		double x1 = a + delta;
		double x2 = x1 + delta;
		double x3;
		double F_min, y3, X_min, x_, y1, y2;
		iterations = 0;
		while (true)
		{
			//2
			++iterations;
			y1 = f(x1);
			y2 = f(x2);

			if (f(x1) <= f(x2))
				x3 = x1 - delta;
			else
				x3 = x2 + delta;

			//4
			y3 = f(x3);
			F_min = min({ y1, y2, y3 });

			if (F_min == y1)
				X_min = x1;
			if (F_min == y2)
				X_min = x2;
			if (F_min == y3)
				X_min = x3;

			a1 = static_cast<double>(f(x2) - f(x1)) / (x2 - x1);
			a2 = (1.0 / (x3 - x2)) * (static_cast<double>(f(x3) - f(x1)) / (x3 - x1) - static_cast<double>(f(x2) - f(x1)) / (x2 - x1));
			x_ = static_cast<double>(x2 + x1) / 2 - static_cast<double>(a1) / (2 * a2);


			if (abs(F_min - f(x_)) < eps && abs(X_min - x_) < eps)
				break;
			else
			{
				delta = static_cast<double>(delta) / tau;
				x1 = min(X_min, x_) - delta;
				x2 = min(X_min, x_);
				x3 = min(X_min, x_) + delta;
			}
		}

		double x = min(X_min, x_);
		return make_pair(f(x), x);
	}

	virtual double getCountOfIter() const
	{
		return iterations;
	}
};

