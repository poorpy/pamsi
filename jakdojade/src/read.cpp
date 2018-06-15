#include "../inc/read.hpp"

Graph parseFileToGraph(const std::string & pathToFile, const std::string & delimeter){
  std::ifstream infile(pathToFile);

  std::string line;
  std::vector<std::string> tokens = {};

  Graph graph = Graph();

  while(std::getline(infile, line)){
    size_t pos = 0;
    while( (pos = line.find(delimeter)) != std::string::npos ){
      tokens.emplace_back(line.substr(0, pos));
      line.erase(0, pos + delimeter.length());
    }
  }

  while( not tokens.empty() ){
    std::string name = std::move(tokens[0]);
    id_t id = std::stoi( tokens[1] );
    float xPos = std::stof( tokens[2] );
    float yPos = std::stof( tokens[3] );
    
    graph.addVertex( Vertex(id, xPos, yPos, name) );

    tokens.erase( tokens.begin(), tokens.begin() + 4 );
  }

  return graph;
}

std::list<edge> parseFileToEdges(const std::string & pathToFile,
                                 const std::string & delimeter){
  std::ifstream infile(pathToFile);

  std::string line;
  std::vector<std::string> tokens = {};

  std::list<edge> edges = {};

  while(std::getline(infile, line)){
    size_t pos = 0;
    while( (pos = line.find(delimeter)) != std::string::npos ){
      tokens.emplace_back(line.substr(0, pos));
      line.erase(0, pos + delimeter.length());
    }
  }

  while( not tokens.empty() ){
    edge newEdge = {
        std::stoi(tokens[0]),
        std::stoi(tokens[1]),
        std::stoi(tokens[2])
    };

    edges.emplace_back(newEdge);
    tokens.erase( tokens.begin(), tokens.begin() + 3 );
  }

  return edges;
}
