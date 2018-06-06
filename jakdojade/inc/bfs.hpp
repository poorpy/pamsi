
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
  /**
   * @brief breadth-first search function
   *
   * Function implements BFS algorithm on weighted undirected graph
   *
   * @param graph Graph to be searched
   * @param start ID of starting vertex
   *
   * @return struct containing MST and map of distance
   */
  TraverseData bfs ( Graph& graph, id_t start );

  /**
   * @brief builds path from MST
   *
   * @param graph Graph to be searched
   * @param start ID of starting vertex
   * @param stop ID of final vertex
   *
   * @return list containing IDs of vertices on path 
   */
  std::list<Vertex> buildPath( Graph & graph, id_t start, id_t stop );
}
