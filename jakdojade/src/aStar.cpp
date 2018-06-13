#include "../inc/aStar.hpp"
#include <limits>
#include <math.h>

const Vertex* astar::Astar::findSmallest ( const std::set<const Vertex*> & mySet, 
    const std::map<Vertex, float> & myScore ){ 
  const Vertex* smallestPtr = *mySet.begin();
  for ( auto const item : mySet ){
    if ( myScore.at( *item ) < myScore.at( *smallestPtr ) ){
      smallestPtr = item;
    }
  }
  return smallestPtr;
}


float astar::Astar::distanceHeuristic ( const Vertex & v1, const Vertex & v2 ){
  float x = v1.getX() - v2.getX();
  float y = v1.getY() - v2.getY();
  return sqrtf( x*x + y*y );
};

TraverseData astar::Astar::aStar( Graph & graph, id_t start, id_t stop ){
  std::set<const Vertex*>  closedSet = {}, openSet = {};
  std::map<Vertex, float> gScore = {}, fScore = {};

  auto traverseData = TraverseData();
  auto const & bVertex = graph.getVertex(start);
  auto const & eVertex = graph.getVertex(stop);
  openSet.emplace(&bVertex);

  for ( auto const & v1 : graph.getVertices() ){
    traverseData.parentMap[v1] = NULL;
    traverseData.distanceMap[v1] = std::numeric_limits<int>::max();
    gScore[v1] = std::numeric_limits<int>::max();
    fScore[v1] = std::numeric_limits<int>::max();
  }

  gScore[bVertex] = 0;
  fScore[bVertex] = distanceHeuristic( bVertex, eVertex );

  while ( not openSet.empty() ){
    const Vertex * current = findSmallest( openSet, fScore );
    if ( *current == eVertex ){
      return traverseData;
    }

    openSet.erase(current);
    closedSet.insert(current);

    for ( auto & vPair : graph.getMatrix().at(*current) ){
      if ( vPair.second != 0 ){
        if ( not closedSet.count(& vPair.first) ){
          if ( not openSet.count(& vPair.first) ){
            openSet.insert(& vPair.first);
          }
          auto tentative_gScore = gScore[*current] + vPair.second;
          if ( tentative_gScore < gScore.at(vPair.first) ){
            traverseData.parentMap[vPair.first] = *current;
            gScore[vPair.first] = tentative_gScore;
            fScore[vPair.first] = gScore.at(vPair.first) + 
              distanceHeuristic(vPair.first, eVertex);
          }
        }
      }
    }
  }

  return traverseData;
}

TraverseData astar::Astar::operator()( Graph & graph, id_t start, id_t stop ){
  return astar::Astar::aStar( graph, start, stop );
}
