from fractions import Fraction

def factorial(num):
    res = 1

    for i in range(1, num + 1):
        res *= i;

    return res

# for i in range(0, 10):
#     print(i, factorial(i))

a = Fraction(1, factorial(10000))
b = Fraction(1, factorial(20000))

c = a / b
print(c)
