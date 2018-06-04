
#pragma once
#include "graph.hpp"
#include <queue>

/**
 * @brief contains all of BFS-related stuff
 *
 * Namespace containing definitions of all BFS-related classes,functions and enums
 */
namespace bfs{
  enum Color { white, gray, black };
  struct TraverseData{

    std::map<Vertex, Vertex> parentMap = {};
    std::map<Vertex, int> distanceMap = {};

    TraverseData() {};
    TraverseData(std::map<Vertex,Vertex> newParentMap,
        std::map<Vertex, int> newDistanceMap);
  };
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
  //std::list<const Vertex&>
  bfs::TraverseData bfs ( Graph& graph, id_t start );
  std::list<Vertex> buildPath( Graph & graph, id_t start, id_t stop );
}
