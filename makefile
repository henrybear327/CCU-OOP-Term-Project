DEBUGMODE=-DDEBUG=2

# target name: dependencies filenames
# target will be rebuild if at least one of the dependencies has been changed

# different types of build
normal: BigInt.o Rational.o Complex.o main.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o Complex.o main.o -o normal

debug: BigIntDebug.o RationalDebug.o ComplexDebug.o testSuite.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector BigIntDebug.o RationalDebug.o ComplexDebug.o testSuite.o -o debug

test: BigInt.o Rational.o Complex.o testSuite.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o Complex.o testSuite.o -o test

# dependicies
# debug versions
BigIntDebug.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector $(DEBUGMODE) -c BigInt.cpp -o BigIntDebug.o

RationalDebug.o: Rational.h Rational.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector $(DEBUGMODE) -c Rational.cpp -o RationalDebug.o

ComplexDebug.o: Complex.h Complex.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector $(DEBUGMODE) -c Complex.cpp -o ComplexDebug.o

mainDebug.o: main.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector $(DEBUGMODE) -c main.cpp -o mainDebug.o

testSuite.o: testSuite.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -g $(DEBUGMODE) -c testSuite.cpp -o testSuite.o

#normal versions
BigInt.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c BigInt.cpp -o BigInt.o

Rational.o: Rational.h Rational.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c Rational.cpp -o Rational.o

Complex.o: Complex.h Complex.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 -c Complex.cpp -o Complex.o

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
