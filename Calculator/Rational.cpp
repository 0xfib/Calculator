#include "stdafx.h"
#include "Rational.h"


Rational::Rational()
{
	numarator = 0;
	numitor = 1;
}

Rational::Rational(int t,int b)
{
	int div = CMMDC(t, b);
	numarator = t/div;
	numitor = b/div;
}

int Rational::CMMDC(int a, int b)
{
	int r;
	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int Rational::CMMMC(int a, int b)
{
	return(a*b / CMMDC(a, b));;
}

Rational Rational::operator+(Rational &right)
{
	int bottom = CMMMC(numitor, right.getNumitor());
	int top = numarator + right.getNumarator();
	return Rational(top,bottom);
}

Rational Rational::operator-(Rational &right)
{
	int bottom = CMMMC(numitor, right.getNumitor());
	int top = numarator - right.getNumarator();
	return Rational(top, bottom);
}

Rational Rational::operator*(Rational &right)
{
	int bottom = numitor * right.getNumitor();
	int top = numarator * right.getNumarator();
	return Rational(top, bottom);
}

Rational Rational::operator/(Rational &right)
{
	int bottom = numitor * right.getNumarator();
	int top = numarator * right.getNumitor();
	return Rational(top, bottom);
}

CString Rational::toString()
{
	CString a;
	a.Format(_T("%d"), numarator);
	CString b;
	b.Format(_T("%d"), numitor);
	return CString(_T("(") + a  + _T("/") + b +_T(")"));
}

int Rational::getNumarator()
{
	return numarator;
}

int Rational::getNumitor()
{
	return numitor;
}

Rational::~Rational()
{
}
