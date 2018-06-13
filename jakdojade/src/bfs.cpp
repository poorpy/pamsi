#include "../inc/bfs.hpp"
#include <limits>
#include <functional>


TraverseData bfs::BFS::bfs( Graph& graph, id_t start ){
  auto traverseData = TraverseData(); 
  std::map<Vertex, bfs::Color> colorMap = {};

  for( auto const & vertex : graph.getVertices() ){
    traverseData.parentMap[vertex] = NULL;
    traverseData.distanceMap[vertex] = std::numeric_limits<int>::max();
    colorMap[vertex] = white;
  }

  auto const & bVertex = graph.getVertex(start);
  traverseData.parentMap[bVertex] = NULL;
  traverseData.distanceMap[bVertex] = 0;
  colorMap[bVertex] = gray; 

  std::queue<const Vertex *> bfsQueue = {};
  bfsQueue.push(&bVertex);
  
  while( not bfsQueue.empty() ){
    auto const & parent = * bfsQueue.front();
    bfsQueue.pop();
    for( auto const & vPair : graph.getMatrix().at(parent) ){
      if ( vPair.second != 0 ){
        if ( colorMap[vPair.first] == white ){
          colorMap[vPair.first] = gray;
          traverseData.parentMap[vPair.first] = parent;
          traverseData.distanceMap[vPair.first] = traverseData.distanceMap[parent] + vPair.second;
          bfsQueue.push(&vPair.first);
        }
      }
    }
    colorMap[parent] = black;
  }

  return traverseData;
}

TraverseData bfs::BFS::operator()( Graph & graph, id_t start, id_t stop ){
  return bfs::BFS::bfs(graph, start);
}
