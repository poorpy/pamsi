#include "../inc/bfs.hpp"
#include "../inc/dfs.hpp"
#include <iostream>

int main(){
  
Graph myGraph = Graph({
  Vertex(1), Vertex(2), Vertex(3),
  Vertex(4), Vertex(5), Vertex(6),
  Vertex(7)},{
  {1,2,1}, {1,3,1}, {1,5,1}, {2,4,1}, {2,6,1},
  {3,7,1}, {5,6,1}});

auto myList = dfs::buildPath(myGraph, 1, 7);


for( auto & item : myList ){
  std::cout << item << std::endl;
}

  return 0;
}
