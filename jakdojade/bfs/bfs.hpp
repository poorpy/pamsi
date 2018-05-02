#include "../graph/src/graph.hpp"
#include <queue>
#include <optional>

/**
 * @brief contains all of BFS-related stuff
 * 
 * Namespace containing definitions of all BFS-related classes,functions and enums
 */
namespace bfs{
  enum Color { white, gray, black };
  struct TraverseData{
    
    static std::map<Vertex, Vertex> parentMap;
    static std::map<Vertex, int> distanceMap;
  
    TraverseData() {};
    TraverseData(std::map<Vertex,Vertex> & newParentMap,
        std::map<Vertex, int> & newDistanceMap);
  };
  /**
   * @brief breadth-first search function
   *  
   * Function implements BFS algorithm on weighted undirected graph 
   *
   * @param graph Graph to be searched
   * @param start ID of starting vertex
   * @param stop  ID of goal vertex
   *
   * @return search tree 
   */
  //std::list<const Vertex&> 
  bfs::TraverseData bfs ( Graph& graph, id_t start );
  std::list<Vertex*> buildPath( Graph graph, TraverseData data, id_t start, id_t stop );
}
