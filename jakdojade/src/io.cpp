#include "../inc/io.hpp"

void listenAndExecute(std::istream & inputStream, Graph & graph, astar::Astar & aStar){
  id_t id1, id2;
  while ( inputStream >> id1 >> id2 ){
    auto myPath = buildPath( graph, id1, id2, aStar );
    for ( auto const & stop : myPath ){
      std::cout << stop << std::endl;
    }
  }
}
