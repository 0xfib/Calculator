#pragma once
class Rational
{
public:
	Rational();
	Rational(int t, int b);
	Rational simplificare(int a, int b);
	int getNumarator();
	int getNumitor();
	int CMMDC(int a, int b);
	int CMMMC(int a, int b);
	Rational operator +(Rational &right);
	Rational operator -(Rational &right);
	Rational operator *(Rational &right);
	Rational operator /(Rational &right);
	CString toString();
	~Rational();
private:
	int numarator;
	int numitor;
};

