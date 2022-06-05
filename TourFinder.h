
#pragma once
#include "Graph.h"

class TourFinder {
  
public:
  /**
  * Creates a empty Tour Finder
  */
  TourFinder();
  
  /**
  * Finds a long tour starting and ending at rootID in the given graph g
  * @param g graph in which to look for a tour
  * @param rootID nodeID in which to start and end tour
  * @return vector of the nodes in the cycle/tour, starting and ending with rootID
  *         return an empty list if a cycle does not exist with rootID
  */
  std::vector<int> findTour(const Graph& g, int rootID);

private:

  // a tree computed by compute_DFS_tree
  Graph DFS_tree_;

  int nodeID_deepest_so_far_;

  // computes a DFS tree of the graph
  // computes the deepest node so far that is connected to the root by backedge 
  void compute_DFS_tree(const Graph& g, int rootID);

};
