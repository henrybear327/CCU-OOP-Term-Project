DEBUGMODE=-DDEBUG=2

# dependicies
BigIntDebug.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -std=c++11 $(DEBUGMODE) -c BigInt.cpp -o BigIntDebug.o

mainDebug.o: main.cpp
	g++ -Wall -Wextra -std=c++11 $(DEBUGMODE) -c main.cpp -o mainDebug.o

BigIng.o: BigInt.h BigInt.cpp
	g++ -Wall -Wextra -std=c++11 -c BigInt.cpp -o BigInt.o

main.o: main.cpp
	g++ -Wall -Wextra -std=c++11 -c main.cpp -o main.o

# type of build
normal: BigInt.o main.o
	g++ -Wall -Wextra -std=c++11 BigInt.o main.o -o normal

debug: BigIntDebug.o mainDebug.o
	g++ -Wall -Wextra -std=c++11 BigIntDebug.o mainDebug.o -o debug

test:
	g++ -Wall -Wextra -std=c++11 -O2 testSuite.cpp -o test

# helpers
format:
	clang-format -i -style=LLVM *.cpp
	astyle --style=linux *.cpp
	clang-format -i -style=LLVM *.h
	astyle --style=linux *.h

clear:
	-rm *.o
	-rm *.orig
	-rm *.gch
	-rm a.out
