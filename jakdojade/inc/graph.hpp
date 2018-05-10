/** \file
 *  File contains definitions for classes Vertex and Graph
 *  \author Bartosz Marczyński
 */

#pragma once
#include <map>
#include <list>
#include <iterator>
#include <algorithm>
typedef unsigned int id_t;
typedef unsigned int weight;

class Vertex{
  id_t id=0;/**< Vertex ID */
  std::list<std::pair<id_t,weight>> adjacentIDs = {}; /**< IDs of adjacent vertices */

  public:
  /**
   * @brief 
   *
   * @return 
   */
  id_t getID() const {return id;}
  /**
   * @brief 
   *
   * @param newID
   */
  void setID(id_t newID) {id = newID;}
  /**
   * @brief 
   *
   * @return 
   */
  std::list<std::pair<id_t, weight>> const& getAdjacent() const {return adjacentIDs;}
  void addAdjacent(std::pair<id_t,weight> newID) {adjacentIDs.emplace_back(newID);}
  void delAdjacent(id_t delID){adjacentIDs.remove_if([&](std::pair<id_t, weight> myPair)
      {return myPair.first == delID;});}

  Vertex() = default;
  Vertex(id_t newID){id = newID;}
  Vertex(id_t newID, std::list<std::pair<id_t, weight>> newAdjacent);

  inline bool operator < (const Vertex& vertex) const {return id < vertex.getID();}
  inline bool operator == (const Vertex& vertex) const { return id == vertex.getID();}
};

class Graph {
  std::list<Vertex> vertices;
  std::map<Vertex, std::map<Vertex,int>> adjacencyMatrix;
  public:
  void addVertex(Vertex newVertex);
  void delVertex(id_t id);
  void updateMatrix();
  Vertex& getVertex(id_t id);
  Graph(std::list<Vertex> newVertices);
  auto const & getMatrix() const {return adjacencyMatrix;}
  auto const & getVertices() const {return vertices;}
};

std::ostream& operator << (std::ostream& outStream, const Vertex& vertex);
std::ostream& operator << (std::ostream& outStream, const Graph& graph);
