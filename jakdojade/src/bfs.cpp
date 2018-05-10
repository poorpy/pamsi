#include "../inc/bfs.hpp"
#include <limits>
#include <functional>

bfs::TraverseData::TraverseData(std::map<Vertex,Vertex> newParentMap,
    std::map<Vertex, int> newDistanceMap){
  parentMap = std::move(newParentMap);
  distanceMap = std::move(newDistanceMap);
}

bfs::TraverseData bfs::bfs( Graph& graph, id_t start ){
  auto traverseData = bfs::TraverseData(); 
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

std::list<Vertex> bfs::buildPath( Graph & graph, id_t start, id_t stop ){
  bfs::TraverseData pathData = bfs::bfs(graph, start);
  std::list<Vertex> pathList = {};

  auto vertex = graph.getVertex(stop);
  while( vertex != graph.getVertex(start)){
    pathList.push_front(vertex);
    vertex = pathData.parentMap[vertex];
  }
  pathList.push_front(vertex);

  return pathList;
}
