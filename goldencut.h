
#include "stdafx.h"
#include "Action.h"
#include "f.h"
using std::make_pair;

//гнкнрне яевемхе
class GoldenCut : public Action
{
public:
	GoldenCut() = default;

	virtual pair<double, double> operator()(double aa, double bb, double epss)
	{
		a = aa;
		b = bb;
		eps = epss;

		double x1, x2, x;
		double y1, y2;
		double fi = 1.618;
		iterations = 0;
		while (true)
		{
			++iterations;
			x1 = b - static_cast<double>(b - a) / fi;
			x2 = a + static_cast<double>(b - a) / fi;

			y1 = f(x1);
			y2 = f(x2);

			if (y1 >= y2)
			{
				a = x1;
				x1 = x2;
				x2 = a + static_cast<double>(b - a) / fi;
			}
			else {
				b = x2;
				x2 = x1;
				x1 = b - static_cast<double>(b - a) / fi;
			}

			if (abs(b - a) < eps)
			{
				x = static_cast<double>(a + b) / 2;
				return make_pair(f(x), x);
			}
		}

	}

	virtual double getCountOfIter() const
	{
		return iterations;
	}


};



