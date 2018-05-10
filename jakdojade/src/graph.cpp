#include "graph.hpp"
#include <iomanip>
#include <iostream>

Vertex::Vertex(id_t newID, std::list<std::pair<id_t, weight>> newAdjacent){
  id = newID;
  for(auto id : newAdjacent){
    adjacentIDs.emplace_back(id);
  }
}

Vertex& Graph::getVertex(id_t id){
  auto findIter = std::find_if(vertices.begin(),vertices.end(),
      [=] (Vertex& vertice) {return vertice.getID() == id; });
  return *findIter;
}

void Graph::addVertex(Vertex newVertex){
  vertices.emplace_back(newVertex);
  adjacencyMatrix.emplace(std::pair<Vertex,std::map<Vertex,int>>(newVertex,{}));
  for(auto const & vertex : vertices){
    adjacencyMatrix[vertex].insert({newVertex,0});
    adjacencyMatrix[newVertex].insert({vertex,0});
  }
  updateMatrix();
};

void Graph::delVertex(id_t id){
  for(auto & vertex : vertices){
   vertex.delAdjacent(id);
  }
  adjacencyMatrix.erase(getVertex(id));
  vertices.remove(getVertex(id));

}

void Graph::updateMatrix(){
  for(auto const & vertex : vertices){
    for(auto adjacentID : vertex.getAdjacent()){
      //TODO Throw exception and/or ask to fix data
      //NOW  First edge overrides weight value to ensure symmetry
      if(adjacencyMatrix[vertex][this->getVertex(adjacentID.first)]==0){
        adjacencyMatrix[vertex][this->getVertex(adjacentID.first)]=adjacentID.second;
        adjacencyMatrix[this->getVertex(adjacentID.first)][vertex] = adjacentID.second;
      }
    }
  }
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
  updateMatrix();
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
