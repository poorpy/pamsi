#include "../inc/graph.hpp"
#include <iomanip>
#include <iostream>

Vertex::Vertex( id_t newID, int newXPos, int newYPos ) {
  id = newID;
  xPos = newXPos;
  yPos = newYPos;
}

auto Graph::getVertex(id_t id) const -> Vertex const &{
  auto findIter = std::find_if(vertices.begin(),vertices.end(),
      [=] (Vertex const & vertice) {return vertice.getID() == id; });
  return *findIter;
}

void Graph::addVertex(Vertex newVertex){
  vertices.emplace_back(newVertex);
  adjacencyMatrix.emplace(std::pair<Vertex,std::map<Vertex, weight>>(newVertex,{}));
  for(auto const & vertex : vertices){
    adjacencyMatrix[vertex].insert({newVertex,0});
    adjacencyMatrix[newVertex].insert({vertex,0});
  }
};

void Graph::addEdge(edge newEdge){
  auto const & bVertex = this->getVertex( std::get<0>(newEdge) );
  auto const & eVertex = this->getVertex( std::get<1>(newEdge) );
  adjacencyMatrix[bVertex][eVertex] = std::get<2>( newEdge );
  adjacencyMatrix[eVertex][bVertex] = std::get<2>( newEdge );
}

void Graph::delVertex(id_t id){
  adjacencyMatrix.erase(getVertex(id));
  vertices.remove(getVertex(id));
}

void Graph::delEdge(id_t id1, id_t id2){
  auto const & bVertex = this->getVertex(id1);
  auto const & eVertex = this->getVertex(id2);
  adjacencyMatrix[bVertex][eVertex] = 0;
  adjacencyMatrix[eVertex][bVertex] = 0;
}

Graph::Graph(std::list<Vertex> newVertices){
  for(auto x : newVertices){
    vertices.emplace_back(x);
  }

  for(auto const & v1: newVertices){
    for(auto const & v2 : newVertices){
      adjacencyMatrix[v1][v2]=0;
    }
  }
} 

Graph::Graph(std::list<Vertex> newVertices, std::list<edge> newEdges) : Graph(std::move(newVertices)){
  for( auto const & someEdge : newEdges ){
    addEdge(someEdge);
  }
}

TraverseData::TraverseData(std::map<Vertex,Vertex> newParentMap,
    std::map<Vertex, int> newDistanceMap){
  parentMap = std::move(newParentMap);
  distanceMap = std::move(newDistanceMap);
}

std::ostream& operator << (std::ostream& outStream, const Vertex& vertex){
  outStream << vertex.getID();
  return outStream;
}

std::ostream& operator << (std::ostream& outStream, const Graph& graph){
  outStream << std::setw(4) << ' ';
  for(auto const & vertex : graph.getVertices()){
    outStream << std::setw(4) << vertex.getID() << ' ';
  }
  outStream << std::endl;

  for(auto const & v1 : graph.getVertices()){
    outStream << std::setw(4) << v1.getID() << ' ';
    for(auto const & v2 : graph.getVertices()){
      outStream << std::setw(4) << graph.getMatrix().at(v1).at(v2) << ' ';
    }
    outStream << std::endl;
  }

  return outStream;
}
