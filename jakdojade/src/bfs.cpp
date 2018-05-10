#include "../inc/bfs.hpp"
#include <limits>
#include <functional>

bfs::TraverseData::TraverseData(std::map<Vertex,Vertex> newParentMap,
    std::map<Vertex, int> newDistanceMap){
  parentMap = std::move(newParentMap);
  distanceMap = std::move(newDistanceMap);
}

bfs::TraverseData bfs::bfs( Graph& graph, id_t start ){
  std::map<Vertex, bfs::Color> colorMap = {};
  TraverseData traverseData = TraverseData();

  for( auto const& vertex : graph.getVertices() ){
    colorMap[vertex] = white;
    traverseData.distanceMap[vertex] = std::numeric_limits<int>::max();
    traverseData.parentMap[vertex] = NULL;
  }

  auto const & bVertex = graph.getVertex(start); //begin Vertex
  auto const & aMatrix = graph.getMatrix();

  colorMap[bVertex] = gray;
  traverseData.distanceMap[bVertex] = 0;

  std::queue<Vertex> bfsQueue = {};
  bfsQueue.push(bVertex);

  do{
    auto const parent = bfsQueue.front(); //std::reference_wrapper<const Vertex> 
    for( auto adjacent : aMatrix.at(parent)){
      auto child = adjacent.first;
      bfsQueue.pop();
      if( aMatrix.at(parent).at( child ) not_eq 0 and colorMap[child] == white ){
        colorMap[child] = gray;
        traverseData.distanceMap[child] = traverseData.distanceMap[parent] + adjacent.second;
        traverseData.parentMap[child] = parent;
        bfsQueue.push(child);

      }
    }
    colorMap[parent] = black;
  }while( !bfsQueue.empty() );

  return traverseData;
}

std::list<Vertex> bfs::buildPath( Graph & graph, id_t start, id_t stop ){
  const Vertex & bVertex = graph.getVertex(start);
  auto & eVertex = graph.getVertex(stop);

  bfs::TraverseData pathData = bfs::bfs(graph, start);
  std::list<Vertex> pathList = {};

  auto vertex = eVertex;
  while(pathData.parentMap[vertex] != bVertex){
    pathList.push_back(vertex);
    vertex = pathData.parentMap[vertex];
  }

  return pathList;
}
