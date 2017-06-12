#include<algorithm>
using namespace std;
#include"BigInt.h"

namespace BigIntNamespace
{
    BigInt::BigInt()
    {
        data.push_back(0);
        isNegative = false;
    }
    BigInt::BigInt(int number)
    {
        if(number < 0)
        {
            isNegative = true;
            number *= -1;
        }
        else
            isNegative = false;
        data.reserve(floor(log(10) + 1));
        for( ; number > 0; )
        {
            data.push_back(number % 10);
            number /= 10;
        }
    }
    BigInt::BigInt(string number)
    {
        int i;
        if(number[0] == '-')
        {
            isNegative = true;
            data.reserve((number.length()) - 1);
            for(i = number.length() -1 ; i >= 1 ; i --)
                data.push_back(number[i] - '0');
        }
        else
        {
            isNegative = false;
            data.reserve(number.length());
            for(i = number.length() -1 ; i >= 0 ; i --)
                data.push_back(number[i] - '0');
        }
    }
    BigInt::BigInt(vector<int> &newData, bool newIsNegative)
    {
        this->data = newData;
        for(int i = ((int)this->data.size()) -1 ; i >= 0 ; i --)
        {
            if(data[i] == 0)
                data.pop_back();
            else
                break;
        }
    }

    BigInt& BigInt::operator =(const BigInt& rightSide)
    {
        if(this == &rightSide)
            return *this;
        this->isNegative = rightSide.isNegative;
        this->data = rightSide.data;

        return *this;
    }
    BigInt operator+(const BigInt &a, const BigInt &b)
    {
        if(a.isNegative == b.isNegative)
        {
            vector<int> tmp;
            int maxSize = max(a.data.size(),b.data.size());
            tmp.reserve(maxSize + 1);

            //counting
            int bring = 0,sum = 0;
            for(int i = 0; i < maxSize ; i ++)
            {
                sum += bring;
                if(i < (int)a.data.size())
                    sum += a.data[i];
                if(i < (int)b.data.size())
                    sum += b.data[i];

                tmp.push_back(sum % 10);
                bring = (sum) / 10;
                sum = 0;
            }
            if(bring != 0)
                tmp.push_back(bring);
            return BigInt(tmp,a.isNegative);
        }
        else
        {
            if(a.isNegative)
                return b - (-a);
            else
                return a - (-b);
        }
    }

    BigInt operator-(const BigInt &a, const BigInt &b)
    {
        if(a.isNegative == b.isNegative)
        {
            if(a.isNegative)
                return a + (-b);
            if(a < b)
                return -(b - a);
            int maxSize = max(a.data.size(),b.data.size());

            vector<int> tmp;
            tmp.reserve(maxSize + 1);

            //counting
            int borrow = 0,diff = 0,temp = 0;
            for(int i = 0; i < maxSize ; i ++)
            {
                temp = a.data[i] - borrow;
                borrow = 0;
                if(temp < b.data[i])
                    borrow = 1;
                diff = (temp + (borrow * 10) - b.data[i]);

                tmp.push_back(diff);
            }
            #if DEBUG > 0
                assert(borrow == 0);
            #endif // DEBUG
                return BigInt(tmp,false);
        }
        else//a.isNegative != b.isNegative
        {
            if(a.isNegative)//a is negative
                return -((-a) + b);
            else//b is negative
                return a + (-b);
        }
    }
    BigInt operator*(const BigInt &a, const BigInt &b)
    {
        int sign;
        if(a.isNegative != b.isNegative)
            sign = 1;
        else
            sign = 0;


        int maxSize = max(a.data.size(),b.data.size());
        vector<int> tmp((maxSize * 2),0);

        //counting
        for(int i = 0; i < (int)a.data.size() ; i ++)
        {
            for(int j = 0 ; j < (int)b.data.size() ; j ++)
            {
                tmp[i+j] = a.data[i] * b.data[j];
            }
        }
        for(int i = 0; i < (maxSize -1) ; i ++)
        {
            tmp[i+1] = tmp[i] / 10;
            tmp[i] = tmp[i] % 10;
        }

        #if DEBUG > 0
            assert(tmp[maxSize-1] < 10);
        #endif // DEBUG
        return BigInt(tmp, sign);
    }
    BigInt operator/(const BigInt &a, const BigInt &b)
    {
        int sign;
        if(a.isNegative != b.isNegative)
            sign = 1;
        else
            sign = 0;

        vector<int> tmp;
        tmp.reserve(a.data.size());

        BigInt pos = b;
        pos.isNegative = false;

        BigInt scale[11];
        scale[0] = BigInt(0);

        //counting
        for(int i = 1; 1 <= 10 ; i ++)
        {
            BigInt cal = pos * BigInt(i);
            scale[i] = cal;
        }
        BigInt t(0);
        for(int i = (int)a.data.size() - 1; i >= 0 ; i --)
        {
            t = t * BigInt(10) + BigInt(a.data[i]);
            for(int j = 1 ; j <= 10 ; j ++)
            {
                if(scale[j] <= t)
                    continue;
                else
                {
                    tmp.push_back(j - 1);
                    t = t - scale[j - 1];
                    break;
                }
            }
        }
        reverse(tmp.begin(),tmp.end());
        return BigInt(tmp, sign);
    }
    BigInt operator%(const BigInt &a, const BigInt &b)
    {
        return a - (b * (a/b));
    }
    const BigInt BigInt::operator-()const
    {
        BigInt tmp = *this;
        if(tmp.isNegative)
            tmp.isNegative = false;
        else
            tmp.isNegative = true;
        return tmp;
    }
    bool unsignedCmpLessThan(const BigInt &a, const BigInt &b)
    {
        if(a.data.size() != b.data.size())
            return a.data.size() < b.data.size();

        for(int i = (int)a.data.size() - 1 ; i >= 0 ; i --)
        {
            if(a.data[i] != b.data[i])
                return a.data[i] < b.data[i];
        }

        return false;
    }
    bool unsignedCmpLessThanOrEqualTo(const BigInt &a, const BigInt &b)
    {
        if(a.data.size() != b.data.size())
            return a.data.size() < b.data.size();
        for(int i = (int)a.data.size() - 1 ; i >= 0 ; i --)
        {
            if(a.data[i] != b.data[i])
                return a.data[i] < b.data[i];
        }
        return true;
    }
    bool BigInt::operator<(const BigInt &rightSide) const
    {
        if(this->isNegative == rightSide.isNegative)
        {
            if(this->isNegative)
                return unsignedCmpLessThan(rightSide,*this);
            else
                return unsignedCmpLessThan(*this,rightSide);
        }
        else
        {
            if(this->isNegative)
                return true;
            else
                return false;
        }
    }
    bool BigInt::operator<=(const BigInt &rightSide) const
    {
        if(this->isNegative == rightSide.isNegative)
        {
            if(this->isNegative)
                return unsignedCmpLessThan(rightSide,*this);
            else
                return unsignedCmpLessThan(*this,rightSide);
        }
        else
        {
            if(this->isNegative)
                return true;
            else
                return false;
        }
    }
    bool BigInt::operator==(const BigInt &rightSide) const
    {
        if(this->isNegative != rightSide.isNegative)
            return false;
        if(this->data.size() != rightSide.data.size())
            return false;
        for(int i = 0 ; i < this->data.size() ; i ++)
        {
            if(this->data[i] != rightSide.data[i])
                return false;
        }

        return true;
    }
    ostream &operator<<(ostream &output, const BigInt &a)
    {
        output << a.toString();
        return output;
    }
    BigInt BigInt::factorial() const
    {
        BigInt plus1(1),tmp(1);
        for(BigInt i(1); i <= *this ; i = (plus1 + i))
            tmp = tmp * i;

        return tmp;
    }
    string BigInt::toString() const
    {
        string res = "";
        if(isNegative)
            res += '-';
        for(int i = data.size() - 1 ; i >= 0 ; i --)
            res += data[i] + '0';

        return res;
    }
    const BigInt gcd(const BigInt &a, const BigInt &b)
    {
        BigInt x = a,y = b,tmp,zero(0);
        while(zero < x)
        {
            tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
    int gcd(const int a,const int b)
    {
        int r,m = a,n = b;
        while(n != 0)
        {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
}
