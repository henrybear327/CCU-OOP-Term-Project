#include"Rational.h"
#include<algorithm>
using namespace std;
#include"BigInt.h"
using namespace BigIntNamespace;

namespace RationalNamespace
{
	Rational::Rational()
	{
		numerator=BigInt(0);
		denominator=BigInt(1);
	}
	Rational::Rational(int a,int b)
	{
		int sa=(a<0?-1:1),sb=(b<0?-1:1);
		a=abs(a);
		b=abs(b);
		int tmp=gcd(a,b);
		a*=(sa*sb);
		numerator=BigInt(a/tmp);
		denominator=BigInt(b/tmp);
	}
	Rational::Rational(BigInt a,BigInt b)
	{
		BigInt tmp(0);
		int sa=(tmp<=a?1:-1),sb=(tmp<=b?1:-1);
		if(sa<0)a=a*BigInt(sa);
		if(sb<0)b=b*BigInt(sb);
		tmp=gcd(a,b);
		numerator=a/tmp;
		numerator=numerator*BigInt(sa*sb);
		denominator=b/tmp;
	}

	Rational operator+(const Rational &a,const Rational &b)
	{
		BigInt n1=a.numerator;
		BigInt n2=b.numerator;
		BigInt d1=a.denominator;
		BigInt d2=b.denominator;
		BigInt rn=n1*d2+n2*d1;
		BigInt rd=d1*d2;
		BigInt tmp=gcd(rn,rd);
		return Rational(rn/tmp,rd/tmp);
	}
	Rational operator-(const Rational &a,const Rational &b)
	{
		BigInt n1=a.numerator;
		BigInt n2=b.numerator;
		BigInt d1=a.denominator;
		BigInt d2=b.denominator;
		BigInt rn=n1*d2-n2*d1;
		BigInt rd=d1*d2;
		BigInt tmp=gcd(rn,rd);
		return Rational(rn/tmp,rd/tmp);
	}
	Rational operator*(const Rational &a,const Rational &b)
	{
		
		BigInt n1=a.numerator;
		BigInt n2=b.numerator;
		BigInt d1=a.denominator;
		BigInt d2=b.denominator;
		BigInt rn=n1*n2;
		BigInt rd=d2*d1;
		BigInt tmp=gcd(rn,rd);
		return Rational(rn/tmp,rd/tmp);
	}
	Rational operator/(const Rational &a,const Rational &b)
	{
		BigInt n1=a.numerator;
		BigInt n2=b.numerator;
		BigInt d1=a.denominator;
		BigInt d2=b.denominator;
		BigInt rn=n1*d2;
		BigInt rd=n2*d1;
		if(rd==BigInt(0)||rd==BigInt(-0))return Rational(0,0);
		int SignRd=BigInt(0)<=rd?1:-1;
		if(SignRd==-1)
		{
			rn=rn*BigInt(-1);
			rd=rd*BigInt(-1);
		}
		BigInt tmp=gcd(rn,rd);
		return Rational(rn/tmp,rd/tmp);
	}
	Rational &Rational::operator=(const Rational &tmp)
	{
		if(this==&tmp)
			return *this;
		this->numerator=tmp.numerator;
		this->denominator=tmp.denominator;
		return *this;
	}
	ostream &operator <<(ostream &out ,const Rational &tmp)
	{
		out<<tmp.numerator<<"/"<<tmp.denominator;
		return out;
	}
	bool Rational::isNegative() const
	{
		return numerator<BigInt(0);
	}
}
