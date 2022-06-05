#include "BFS.h"
#include <iostream>
#include <queue>
BFS::BFS (Graph *g): graph_(g), visitedNodes_(g->getNumNodes(), false) {
    int num_nodes = graph_->getNumNodes();
    
    // Starts traversal at node 0
    for (int i = 0; i < num_nodes; i++) {
        if(!visitedNodes_.at(i)) {
            BFSHelper(i);
        }
    }
}

BFS::BFS(Graph *g, int start): graph_(g), visitedNodes_(g->getNumNodes(), false) {
  int num_nodes = graph_->getNumNodes();

  // Starts traversal at desired node
  BFSHelper(start);
  
  for (int i=0; i <num_nodes; i++) {
      if(!visitedNodes_.at(i)) {
          BFSHelper(i);
      }
  }
  
}

void BFS::BFSHelper(int node) {
    int start=node;
    std::queue<int> q;

    visitedNodes_.at(node) = true;
    traversal_.push_back(start);
    
    q.push(node);
    
    while(!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < graph_->getNodeDegree(node); i++) {
            std::pair<int, double> neighbor = graph_->getNeighborForNode(node, i);

            int neighborID = neighbor.first;

            if (!visitedNodes_.at(neighborID)) {
                visitedNodes_.at(neighborID)=true;
                traversal_.push_back(neighborID);
                q.push(neighborID);
            }
        }
    }
}

std::vector<int> BFS:: getVisitedVector() const {
  return traversal_;
}

std::vector<bool> BFS:: getVisitedNodes() const {
  return visitedNodes_;
}