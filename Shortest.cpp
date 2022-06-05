#include "Shortest.h"
#include <iostream>
#include <queue>
#include <limits>

Shortest::Shortest() {
  
}

std::pair<double, std::vector<int>> Shortest::DJ(Graph g, int start, int end) {
    unsigned int numNodes = g.getNumNodes();
    distances.resize(numNodes);
    prev.resize(numNodes);

    //This custom comparator was gotten from: http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
    auto compare = [&](int lhs, int rhs)
                {
                    return (distances.at(lhs) > distances.at(rhs));
                };
    
    //build the priority queue with nodes and comparing the distances
    std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

    for (unsigned n = 0; n < numNodes; n++) {
        if ((int) n == start) {
            //if node is the start, distance is 0 and the previous node is undefined
            distances[n] = 0;
            prev[n] = -1;
        } else {
            //any other node distance is inf
            distances[n] = std::numeric_limits<double>::infinity();
        }
    }

    q.push(start);

     while (!q.empty()) {
        int smal = q.top();
        q.pop();
        //if we are at the end node, stop going through the queue
        if (smal == end) {
            break;
        }
        double distSmal = distances.at(smal);
        //if we haven't visited this node, we see if the new distance beats the old one and update the distance and previous node accordingly
        if (distSmal < std::numeric_limits<double>::infinity()) {
            unsigned int numNeighbors = g.getNodeDegree(smal);
            for (unsigned i = 0; i < numNeighbors; i++) {
                auto neighborPair = g.getNeighborForNode(smal, i);
                int adjNodeID = neighborPair.first;
                double adjNodeWeight = neighborPair.second;

                if ((distSmal + adjNodeWeight) < distances.at(adjNodeID)) {
                    distances[adjNodeID] = distSmal + adjNodeWeight;
                    prev[adjNodeID] = smal;
                    //add the neighbors of the current node to the queue if not visited
                    q.push(adjNodeID);
                }

            }

        }

        
    }
    //build the return vector of the path between the 2 nodes
    std::vector<int> retvector = buildReturnVec(start, end);

    std::pair<double, std::vector<int>> ret = std::pair<double, std::vector<int>>(distances[end], retvector);

    //if the graph isn't connected, return the distance as inf
    if (distances[end] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path between those 2 nodes" << std::endl;
    }

    return ret; 
}

std::vector<int> Shortest::buildReturnVec(int start, int end) {
    std::vector<int> retvector;
    int curr = end;
    while (curr != start) {
        retvector.push_back(curr);
        curr = prev[curr];
    }
    retvector.push_back(start);
    std::reverse(retvector.begin(), retvector.end());
    return retvector;
}
