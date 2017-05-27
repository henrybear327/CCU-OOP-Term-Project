from fractions import Fraction

def factorial(num):
    res = 1

    for i in range(1, num + 1):
        res *= i;

    return res

# for i in range(0, 10):
#     print(i, factorial(i))

a = Fraction(1, 3)
b = Fraction(-6, 17)
c = Fraction(factorial(81), factorial(320))
d = Fraction(factorial(128),factorial(520))
# print(a)
# print(b)
# print(c)
# print(d)

l = a * c + b * d
# print(l)
r = b * c - a * d
# print(r)
down = c * c + d * d
# print(down)

sign = "+"
if Fraction(r, down).numerator < 0:
    val = Fraction(r, down).numerator * -1;
    sign = "-"
print("({0} / {1}) {2} ({3} / {4}) i".format(Fraction(l, down).numerator,
                                           Fraction(l, down).denominator,
                                           sign,
                                           val,
                                           Fraction(r, down).denominator))
