
#pragma once
#include "graph.hpp"
#include <set>

/**
 * @brief contains whole of A*-related stuff
 */
namespace astar{
  float distanceHeuristic ( const Vertex & v1, const Vertex & v2 );
  TraverseData aStar( Graph & graph, id_t start, id_t stop );
  std::list<Vertex> buildPath( Graph & graph, id_t start, id_t stop );
}
