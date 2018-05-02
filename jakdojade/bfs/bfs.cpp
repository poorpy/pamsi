#include "bfs.hpp"
#include <limits>

bfs::TraverseData::TraverseData(std::map<Vertex,Vertex> & newParentMap,
    std::map<Vertex, int> & newDistanceMap){
  parentMap = newParentMap;
  distanceMap = newDistanceMap;
}

bfs::TraverseData bfs::bfs( Graph& graph, id_t start ){
  std::map<Vertex, bfs::Color> colorMap = {};
  TraverseData::distanceMap = {};
  TraverseData::parentMap = {};

  for( auto const& vertex : graph.getVertices() ){
    colorMap[vertex] = white;
    TraverseData::distanceMap[vertex] = std::numeric_limits<int>::max();
    TraverseData::parentMap[vertex] = NULL;
  }
  

  auto const & bVertex =  graph.getVertex(start); //begin Vertex 

  colorMap[bVertex] = gray;
  TraverseData::distanceMap[bVertex] = 0;

  std::queue<Vertex const*> bfsQueue = {};
  bfsQueue.emplace(&bVertex);

  while( !bfsQueue.empty() ){
    Vertex const & parent = * bfsQueue.front();
    bfsQueue.pop();
    for( std::pair<id_t, weight> const & adjacent : parent.getAdjacent() ){
      auto const & child = graph.getVertex(adjacent.first);
      if( colorMap[child] == white ){
        colorMap[child] = gray;
        TraverseData::distanceMap[child] = TraverseData::distanceMap[parent] + adjacent.second;
        TraverseData::parentMap[child] = parent;
        bfsQueue.emplace(&child);
      }
    }
    colorMap[parent] = black;
  }

  return bfs::TraverseData();
}

std::list<Vertex*> buildPath( Graph graph, bfs::TraverseData const & data, id_t start, id_t stop ){
  auto const & bVertex = graph.getVertex(start);
  auto const & eVertex = graph.getVertex(stop);

}
