#pragma once 
#include "graph.hpp"
#include <stack>

namespace dfs{
  enum Color { white, gray, black };
  struct TraverseData{
    std::map<Vertex, Vertex> parentMap = {};
    std::map<Vertex, int> distanceMap = {};
    
    TraverseData() {};
    TraverseData(std::map<Vertex, Vertex> newParentMap,
        std::map<Vertex, int> newDistanceMap);
  };
  
  dfs::TraverseData dfs ( Graph & graph, id_t start );
  std::list<Vertex> buildPath ( Graph & graph, id_t start, id_t stop );
}
