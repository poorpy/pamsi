#pragma once

#include "graph.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

Graph parseFileToGraph(const std::string & pathToFile, const std::string & delimeter);
std::list<edge> parseFileToEdges(const std::string & pathToFile,
                                 const std::string & delimeter);
