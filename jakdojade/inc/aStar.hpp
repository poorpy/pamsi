#pragma once
#include "graph.hpp"
#include <set>

/**
 * @brief contains whole of A*-related stuff
 */
namespace astar{
  class Astar : public SearchAlgorithm{
  private:
    /**
     * @brief Generate MST from given graph
     */
    TraverseData aStar ( Graph& graph, id_t start, id_t stop );
    float distanceHeuristic ( const Vertex & v1, const Vertex & v2 );
    /**
     * @brief Find vertex in mySet which indexes smallest element in myScore map
     */
    const Vertex * findSmallest ( const std::set<const Vertex*> & mySet,
        const std::map<Vertex, float> & myScore );
  public:
    Astar() {};
    virtual TraverseData operator () ( Graph & graph, id_t start, id_t stop );
  };
}
