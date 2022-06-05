
#pragma once
#include <iostream>
#include "Graph.h"
#include <vector>

class Shortest {
  
public:

  /**
  * Creates a empty Shortest Object
  */
  Shortest();

  /**
  * Finds a long tour starting and ending at rootID in the given graph g
  * @param g graph in which to look for a tour
  * @param start nodeID where the path will start
  * @param end nodeID where the path will end
  * @return pair of double and vector of the distance and the nodes in the shortest path between the 2 nodes
  *         print out if there is no path between 2 nodes and return distance of inf
  */
  std::pair<double, std::vector<int>> DJ (Graph g, int start, int end);
  
private:

  //builds the vector of the path, working backwards from the end
  std::vector<int> buildReturnVec(int start, int end);
  
  //vector of distances from the start
  std::vector<double> distances;
  //vector of the node that was before the current node
  std::vector<int> prev;
};
