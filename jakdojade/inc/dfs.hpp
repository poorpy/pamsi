#pragma once 
#include "graph.hpp"
#include <stack>

namespace dfs{
  enum Color { white, gray, black };
  TraverseData dfs ( Graph & graph, id_t start );
  std::list<Vertex> buildPath ( Graph & graph, id_t start, id_t stop );
}
