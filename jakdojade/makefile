DEVFLAGS = -g -Iinc -Wall -pedantic -std=c++17
LINKFLAGS = -Wall -pedantic -std=c++17
RELEASEFLAGS = -Iinc -Wall -pedantic -std=c++17

jakdojade: obj obj/main.o obj/graph.o obj/bfs.o
	clang++ ${LINKFLAGS} -o jakdojade obj/main.o obj/graph.o obj/bfs.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/graph.hpp inc/bfs.hpp 
	clang++ -c ${DEVFLAGS} -o obj/main.o src/main.cpp

obj/graph.o: src/graph.cpp inc/graph.hpp
	clang++ -c ${DEVFLAGS} -o obj/graph.o src/graph.cpp

obj/bfs.o: src/bfs.cpp inc/bfs.hpp
	clang++ -c ${DEVFLAGS} -o obj/bfs.o src/bfs.cpp

clean: 
	rm -rf jakdojade obj/* || true 
