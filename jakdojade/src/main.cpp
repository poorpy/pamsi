#include "../inc/bfs.hpp"
#include <iostream>

int main(){
  
Graph myGraph = Graph({
  Vertex(1), Vertex(2), Vertex(3),
  Vertex(4), Vertex(5), Vertex(6),
  Vertex(7), Vertex(8), Vertex(9),
  Vertex(10)},{
  {1,2,1}, {1,5,4}, {1,6,5}, {1,7,6}, {1,10,9},
  {2,3,1}, {3,4,1}, {3,8,5}, {3,10,7}, {4,5,1},
  {4,8,4}, {4,10,6}, {5,6,1}, {5,8,3}, {6,7,1},
  {7,8,1}, {8,9,1}, {9,10,1}});

std::cout << myGraph;

auto myList = bfs::buildPath(myGraph, 1, 8);

for( auto & item : myList ){
  std::cout << item << std::endl;
}

  return 0;
}
