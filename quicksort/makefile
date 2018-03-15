CXXFLAGS= -pedantic -Wall -Wextra -std=c++17 -g

__start__: quicksort
	./quicksort >> data.csv

quicksort: main.cpp interface.hpp interface.cpp quicksort.cpp quicksort.hpp 
	clang++ ${CXXFLAGS} -o quicksort main.cpp interface.cpp quicksort.cpp
