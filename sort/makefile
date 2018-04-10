CXXFLAGS= -pedantic -Wall -Wextra -std=c++17 -g

__start__: sort 
	./sort 

clean:
	rm sort 

sort: main.cpp interface.hpp interface.cpp heapsort/heapsort.hpp heapsort/heapsort.cpp \
	quicksort/quicksort.hpp quicksort/quicksort.cpp mergesort/mergesort.cpp mergesort/mergesort.hpp
	clang++ ${CXXFLAGS} -o sort main.cpp interface.cpp heapsort/heapsort.cpp \
		quicksort/quicksort.cpp mergesort/mergesort.cpp

