#pragma once
#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

class Goods {
private:
	double first;
	int second;
public:
	Goods();
	Goods(double, int);
	Goods(const Goods&);

	void Setfirst(double);
	void Setsecond(int);
	double Getfirst() const;
	int Getsecond() const;

	Goods& operator = (const Goods&);
	operator string() const;

	friend ostream& operator<<(ostream&, const Goods&);
	friend istream& operator>>(istream&, Goods&);

	Goods& operator ++();
	Goods& operator --();

	Goods operator ++(int);
	Goods operator--(int);

	double Cost();

};
