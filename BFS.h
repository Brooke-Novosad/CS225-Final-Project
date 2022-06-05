
#pragma once
#include<iostream>
#include <vector>
#include "Graph.h"
class BFS {
public:
    /**
    * Creates Breadth First Search starting from node 0.
    * Stores traversal in int vector traversal_.
    * @param g pointer to graph to traverse
    */
    BFS(Graph *g);
    
    /**
    * Creates Breadth First Search starting from node passed in.
    * @param g pointer to graph to traverse
    * @param start node to start BFS from
    */
    BFS(Graph *g, int start);
    
    
    /**
     * Returns BFS traversal vector.
     * @return graph traversal
     */
    std::vector<int> getVisitedVector() const;
    
    /**
    * Gets the vector of the nodes that were visited.
    * Used for BFS testing.
    * @return a vector of the visited nodes
    */
    std::vector<bool> getVisitedNodes() const;
    
  
private:

    /**
     * Helper function for BFS. Runs the main part BFS.
     * @param node node to start BFS from
     */
    void BFSHelper(int node);
    

    Graph *graph_;
    std::vector<bool> visitedNodes_;
    std::vector<int> traversal_;
};
