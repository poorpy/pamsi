#pragma once 
#include "graph.hpp"
#include <stack>

/**
 * @brief contains whole of BFS-related stuff 
 */
namespace dfs{
  enum Color { white, gray, black };
  class DFS : public SearchAlgorithm{
  private:
    TraverseData dfs( Graph& graph, id_t start );
  public:
    DFS() {};
    virtual TraverseData operator () ( Graph & graph, id_t start, id_t stop );
  };
}
