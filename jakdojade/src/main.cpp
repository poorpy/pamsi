#include "../inc/bfs.hpp"
#include "../inc/dfs.hpp"
#include "../inc/aStar.hpp"
#include "../inc/read.hpp"
#include "../inc/io.hpp"
#include <iostream>

int main(){
  std::string edgesFilePath = "./data/connections.csv",
              graphFilePath = "./data/new_stops.csv",
              delimeter = ",";

  auto edgesList = parseFileToEdges(edgesFilePath, delimeter);
  //std::cout << "Number of edges: " << edgesList.size() << std::endl;

  Graph graph = parseFileToGraph(graphFilePath, delimeter);
  //std::cout <<  "Number of vertices: " << graph.getVertices().size() << std::endl;

  for ( auto const & item : edgesList ){
    graph.addEdge(item);
  }
  astar::Astar aStar = astar::Astar();

  listenAndExecute( std::cin, graph, aStar );
  


  return 0;
} 
