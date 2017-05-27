DEBUGMODE=-DDEBUG=2

# different types of build
normal: BigInt.o Rational.o main.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o main.o -o normal

debug: BigIntDebug.o RationalDebug.o mainDebug.o
	g++ -Wall -Wextra -Wshadow -std=c++11 BigIntDebug.o RationalDebug.o mainDebug.o -o debug

test: BigInt.o Rational.o testSuite.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o testSuite.o -o test

# dependicies
# debug versions
BigIntDebug.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c BigInt.cpp -o BigIntDebug.o

RationalDebug.o: Rational.h Rational.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c Rational.cpp -o RationalDebug.o

mainDebug.o: main.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c main.cpp -o mainDebug.o

testSuite.o: testSuite.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c testSuite.cpp -o testSuite.o

#normal versions
BigInt.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c BigInt.cpp -o BigInt.o

Rational.o: Rational.h Rational.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c Rational.cpp -o Rational.o

main.o: main.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c main.cpp -o main.o

# helpers
format:
	clang-format -i -style=LLVM *.cpp
	astyle --style=linux *.cpp
	clang-format -i -style=LLVM *.h
	astyle --style=linux *.h

clear:
	# ignores errors
	# continues to the next command even if one of the rm fails
	-rm *.o
	-rm *.orig
	-rm *.gch
	-rm a.out
