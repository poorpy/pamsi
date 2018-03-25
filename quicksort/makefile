CXXFLAGS= -pedantic -Wall -Wextra -std=c++17 -g

__start__: quicksort
	./quicksort 

clean:
	rm duration.csv quicksort

quicksort: main.cpp interface.hpp interface.cpp quicksort.cpp quicksort.hpp 
	clang++ ${CXXFLAGS} -o quicksort main.cpp interface.cpp quicksort.cpp
