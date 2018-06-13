#include "../inc/bfs.hpp"
#include "../inc/dfs.hpp"
#include "../inc/aStar.hpp"
#include <iostream>

int main(){
  
Graph myGraph = Graph({
  Vertex(1, 0, 0), Vertex(2, -1, -1), Vertex(3, -1, -3),
  Vertex(4, 1, -3), Vertex(5, -1, -1), Vertex(6, -1, -2)},{
  {1,2,2}, {1,5,2}, {2,6,3}, {6,3,3}, {3,4,2},
  {4,5,2}});

bfs::BFS myBFS = bfs::BFS();
dfs::DFS myDFS = dfs::DFS();
astar::Astar myAstar = astar::Astar();

auto myList = buildPath(myGraph, 1, 3, myBFS);

std::cout << "BFS: \n";
for( auto & item : myList ){
  std::cout << item << std::endl;
}

std::cout << "DFS: \n";

myList = buildPath(myGraph, 1, 3, myDFS);

for( auto & item : myList ){
  std::cout << item << std::endl;
}

myList = buildPath(myGraph, 1, 3, myAstar);

for( auto & item : myList ){
  std::cout << item << std::endl;
}
  return 0;
}
