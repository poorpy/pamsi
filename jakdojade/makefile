DEVFLAGS = -g -Iinc -Wall -pedantic -std=c++17
LINKFLAGS = -Wall -pedantic -std=c++17
RELEASEFLAGS = -Iinc -Wall -pedantic -std=c++17

jakdojade: obj obj/main.o obj/graph.o obj/bfs.o obj/dfs.o obj/astar.o
	clang++ ${LINKFLAGS} -o jakdojade obj/main.o obj/graph.o obj/bfs.o obj/dfs.o obj/astar.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/graph.hpp inc/bfs.hpp inc/dfs.hpp inc/aStar.hpp
	clang++ -c ${DEVFLAGS} -o obj/main.o src/main.cpp

obj/graph.o: src/graph.cpp inc/graph.hpp
	clang++ -c ${DEVFLAGS} -o obj/graph.o src/graph.cpp

obj/bfs.o: src/bfs.cpp inc/bfs.hpp
	clang++ -c ${DEVFLAGS} -o obj/bfs.o src/bfs.cpp

obj/dfs.o: src/dfs.cpp inc/dfs.hpp
	clang++ -c ${DEVFLAGS} -o obj/dfs.o src/dfs.cpp

obj/astar.o: src/aStar.cpp inc/aStar.hpp
	clang++ -c ${DEVFLAGS} -o obj/astar.o src/aStar.cpp

clean:
	rm -rf jakdojade obj/* || true
