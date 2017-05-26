all:
	g++ -Wall -Wextra -std=c++11 -c BigInt.cpp -o BigInt.o
	g++ -Wall -Wextra -std=c++11 -c main.cpp -o main.o
	g++ -Wall -Wextra -std=c++11 BigInt.o main.o -o main

test:
	g++ -Wall -Wextra -std=c++11 -O2 testSuite.cpp -o testSuite

format:
	clang-format -i -style=LLVM *.cpp
	astyle --style=linux *.cpp
	clang-format -i -style=LLVM *.h
	astyle --style=linux *.h
