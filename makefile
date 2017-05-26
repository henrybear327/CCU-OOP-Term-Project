all:
	g++ -Wall -Wextra -std=c++11 -O2 main.cpp -o main

format:
	clang-format -i -style=LLVM *.cpp
	astyle --style=linux *.cpp
	clang-format -i -style=LLVM *.h
	astyle --style=linux *.h
