#pragma once
#include "graph.hpp"
#include <queue>

/**
 * @brief contains whole of BFS-related stuff
 *
 * Namespace containing definitions of all BFS-related classes,functions and enums
 */
namespace bfs{
  enum Color { white, gray, black };

  class BFS : public SearchAlgorithm{
  private:
    TraverseData bfs ( Graph& graph, id_t start );
  public:
    BFS() {};
    virtual TraverseData operator () ( Graph & graph, id_t start, id_t stop );
  };
}
