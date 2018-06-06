/** \file
 *  File contains definitions for classes Vertex and Graph
 *  \author Bartosz Marczyński
 */

#pragma once
#include <map>
#include <list>
#include <iterator>
#include <algorithm>
#include <tuple>

typedef unsigned int id_t;
typedef unsigned int weight;
typedef std::tuple<id_t, id_t, weight> edge;

class Vertex{
  id_t id=0;/**< Vertex ID */
  float xPos = 0, yPos = 0; 
  public:
  id_t getID() const {return id;}
  float getX() const {return xPos;}
  float getY() const {return yPos;}

  Vertex() = default;
  Vertex( id_t newID ) {id = newID;}
  Vertex( id_t newID, int newXPos, int newYPos );

  inline bool operator < (const Vertex& vertex) const  { return id <  vertex.getID(); }
  inline bool operator == (const Vertex& vertex) const { return id == vertex.getID(); }
  inline bool operator != (const Vertex& vertex) const { return id != vertex.getID(); }
};

class Graph {
  std::list<Vertex> vertices;
  std::map<Vertex, std::map<Vertex, weight>> adjacencyMatrix;
  public:
  void addVertex(Vertex newVertex);
  void addEdge(edge newEdge);

  void delVertex(id_t id);
  void delEdge(id_t id1, id_t id2);

  auto getVertex(id_t id) const -> Vertex const &;
  auto const & getMatrix() const {return adjacencyMatrix;}
  auto const & getVertices() const {return vertices;}

  Graph(std::list<Vertex> newVertices);
  Graph(std::list<Vertex> newVertices, std::list<edge> newEdges);
};

struct TraverseData{

  std::map<Vertex, Vertex> parentMap = {};
  std::map<Vertex, int> distanceMap = {};

  TraverseData() {};
  TraverseData(std::map<Vertex,Vertex> newParentMap,
      std::map<Vertex, int> newDistanceMap);
};

std::ostream& operator << (std::ostream& outStream, const Vertex& vertex);
std::ostream& operator << (std::ostream& outStream, const Graph& graph);
