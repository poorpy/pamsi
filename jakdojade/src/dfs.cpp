#include "../inc/dfs.hpp"
#include <limits>
#include <iostream>

TraverseData dfs::dfs( Graph& graph, id_t start ){
  auto traverseData = TraverseData(); 
  std::map<Vertex, dfs::Color> colorMap = {};

  for( auto const & vertex : graph.getVertices() ){
    traverseData.parentMap[vertex] = NULL;
    traverseData.distanceMap[vertex] = std::numeric_limits<int>::max();
    colorMap[vertex] = white;
  }

  auto const & bVertex = graph.getVertex(start);
  traverseData.parentMap[bVertex] = NULL;
  traverseData.distanceMap[bVertex] = 0;
  colorMap[bVertex] = white; 

  std::stack<const Vertex *> dfsStack = {};
  dfsStack.push(&bVertex);
  
  while ( not dfsStack.empty() ){
    auto const & parent = * dfsStack.top();
    dfsStack.pop();
    if ( colorMap[parent] == white ){
      colorMap[parent] = gray;
      for (auto const & vPair : graph.getMatrix().at(parent)){
        if ( colorMap.at(vPair.first) == white and vPair.second != 0 ){
          dfsStack.push(&vPair.first);
          traverseData.parentMap[vPair.first] = parent;
          traverseData.distanceMap[vPair.first] = traverseData.distanceMap[parent] + vPair.second;
        }
      }
    }
    colorMap[parent] = black;
  }

  return traverseData;
}

std::list<Vertex> dfs::buildPath( Graph & graph, id_t start, id_t stop ){
  TraverseData pathData = dfs::dfs(graph, start);
  std::list<Vertex> pathList = {};
  auto vertex = graph.getVertex(stop);
  while( vertex != graph.getVertex(start)){
    pathList.push_front(vertex);
    vertex = pathData.parentMap[vertex];
  }
  pathList.push_front(vertex);
  return pathList;
}
