DEBUGMODE=-DDEBUG=2

# target name: dependencies filenames
# target will be rebuild if at least one of the dependencies has been changed

# different types of build
normal: BigInt.o Rational.o Complex.o main.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o Complex.o main.o -o normal

debug: BigIntDebug.o RationalDebug.o ComplexDebug.o mainDebug.o
	g++ -Wall -Wextra -Wshadow -std=c++11 BigIntDebug.o RationalDebug.o ComplexDebug.o mainDebug.o -o debug

test: BigInt.o Rational.o Complex.o testSuite.o
	g++ -Wall -Wextra -Wshadow -std=c++11 -O2 BigInt.o Rational.o Complex.o testSuite.o -o test

clangMain: BigInt.cpp Rational.cpp Complex.cpp main.cpp
	clang++ -emit-obj -fmath-errno  -fuse-init-array -momit-leaf-frame-pointer -dwarf-column-info -debug-info-kind=limited -dwarf-version=4 -debugger-tuning=gdb -O2 -Wall -Wno-unused -std=c++11 -fsanitize=address,alignment,array-bounds,bool,enum,float-cast-overflow,float-divide-by-zero,function,integer-divide-by-zero,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,unreachable,vla-bound,vptr -fno-assume-sane-operator-new -fobjc-runtime=gcc -fno-common -fdiagnostics-show-option -fcolor-diagnostics -fvectorize BigInt.cpp Rational.cpp Complex.cpp main.cpp

# dependicies
# debug versions
BigIntDebug.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c BigInt.cpp -o BigIntDebug.o

RationalDebug.o: Rational.h Rational.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c Rational.cpp -o RationalDebug.o

ComplexDebug.o: Complex.h Complex.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c Complex.cpp -o ComplexDebug.o

mainDebug.o: main.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c main.cpp -o mainDebug.o

testSuite.o: testSuite.cpp
	g++ -Wall -Wextra -Wshadow -std=c++11 $(DEBUGMODE) -c testSuite.cpp -o testSuite.o

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
	-rm normal
	-rm debug
	-rm test
