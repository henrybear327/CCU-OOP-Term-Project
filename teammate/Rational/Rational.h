#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
using namespace std;

#include"BigInt.h"
using namespace BigIntNamespace;

namespace RationalNamespace
{
	class Rational
	{
		public:
			Rational();
			Rational(int a, int b);
			Rational(BigInt a,BigInt b);

			friend Rational operator+(const Rational &a,const Rational &b);
			friend Rational operator-(const Rational &a,const Rational &b);
			friend Rational operator*(const Rational &a,const Rational &b);
			friend Rational operator/(const Rational &a,const Rational &b);
			Rational &operator=(const Rational &tmp);

			friend ostream &operator<< (ostream &out,const Rational &tmp);

			bool isNegative()const;
		private:
			BigInt numerator;
			BigInt denominator;
	};
}
#endif
