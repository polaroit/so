#include "stdafx.h"
#include <utility>
#include <string>

#ifndef SIMP_OPT_H
#define SIMP_OPT_H

class Action;
using std::pair;
using std::string;

class simp_opt
{
private:
	class min_point
	{
	public:
		min_point() = default;
		min_point(const pair<double, double> &p)
			:y_min(p.first), x_min(p.second)
		{};
		min_point &operator=(const pair<double, double> &p)
		{
			y_min = p.first;
			x_min = p.second;
			return *this;
		};

		double y_min;
		double x_min;
	};
	min_point point;
	Action *op;
public:
	simp_opt(const string &);
	~simp_opt();
	min_point operator()(double, double, double);
	void setMethod(const string &);
	double getIter() const;
};


#endif 