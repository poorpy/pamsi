#include "../inc/aStar.hpp"
#include <limits>
#include <math.h>

float distanceHeuristic ( const Vertex & v1, const Vertex & v2 ){
  float x = v1.getX() - v2.getX();
  float y = v1.getY() - v2.getY();
  return sqrtf( x*x + y*y );
};

TraverseData astar::aStar( Graph & graph, id_t start, id_t stop ){
  std::set<Vertex*>  closedSet = {}, openSet = {};
  std::map<Vertex, int> gScore = {}, fScore = {};

  auto traverseData = TraverseData();
  auto const & bVertex = graph.getVertex(start);
  openSet.emplace(&bVertex);

  for ( auto const & v1 : graph.getVertices() ){
    traverseData.parentMap[v1] = NULL;
    traverseData.distanceMap[v1] = std::numeric_limits<int>::max();
    gScore[v1] = std::numeric_limits<int>::max();
    fScore[v1] = std::numeric_limits<int>::max();
  }

  while ( not openSet.empty() ){
    
  }

  return traverseData;
}
