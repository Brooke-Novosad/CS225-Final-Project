#include "Graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>


Graph::Graph() {
  adjList.clear();
}


void Graph::readin(std::string filename, int numNodes) {
  std::ifstream input;
  input.open(filename);
  std::string line;
  std::string space = " ";
  adjList.resize(numNodes, std::vector<std::pair<int, double>>(0));
  if (input.is_open()) {
    int text = 0; 
    while(getline(input, line)) {
      //first 3 lines of file are descriptions 
      if (text > 3) {
        //sees if we are on the first or second number
        bool second = false;
        std::string s1 = "";
        std::string s2 = "";
        for (unsigned i = 0; i < line.length(); i++) {
          if (!second) {
            if (isspace(line[i])) {
              second = true;
            } else {
              s1 = s1 + line.substr(i, 1);
            }
          } else {
            if (!isspace(line[i])) {
              s2 = s2 + line.substr(i, 1);
            }
          }
        }
        //if the number we read in is greater than the number of nodes we want, don't add it to the AdjList (mainly for testing)
        int num1 = std::stoi(s1);
        int num2 = std::stoi(s2);
        if (num1 < numNodes && num2 < numNodes) {
          adjList[num1].push_back(std::pair<int, double>(num2, 0));
        }
      }
      text++;   
    }
  }
  calculateWeights();
}

void Graph:: calculateWeights() {
  std::vector<double> degrees = getDegrees();

  // calculate the weight for every edge using the degrees
  for (unsigned long i = 0; i < adjList.size(); i++) {
    for (unsigned long j = 0; j < adjList[i].size(); j++) {
      auto& pair = adjList[i][j];
      // weight of edge is the sum of the node's degrees / 2
      adjList[i][j].second = (degrees[i] + degrees[pair.first]) / 2;
    }
  }

}

std::vector<double> Graph::getDegrees() const {
  std::vector<double> result;
  result.resize(adjList.size(), 0);
  for (unsigned long i = 0; i < result.size(); i++) {
    // degree of node is the number of adjacent nodes it has
    result[i] = adjList[i].size();
  }
  return result;
}

bool Graph::containsEdge(int first, int second) const {
  if (first >= (int)adjList.size() || second >= (int)adjList.size()) {
    // invalid input, no first nodeID or second nodeID
    return false;
  }

  // if second is in first's adjList, there is an edge between the two
  for (auto p : adjList[first]) {
    if (p.first == second) {
      return true;
    }
  }

  return false;
}

void Graph::addEdge(int first, int second, double weight) {

  if (containsEdge(first, second)) {
    // edge already exists, nothing more to do
    return;
  }

  // resize to fit the new nodes
  int max = std::max(first, second);
  if ((int)adjList.size() <= max) {
    for (int i = adjList.size(); i <= max; i++) {
      adjList.push_back(std::vector<std::pair<int,double>>());
    }
  }

  // add to each other's adjacency list
  adjList[first].push_back(std::pair<int, double>(second, weight));
  adjList[second].push_back(std::pair<int, double>(first, weight));
}

int Graph::getNumNodes() const {
  return adjList.size();
}

int Graph::getNodeDegree(int nodeID) const {
    return adjList.at(nodeID).size();
}

std::pair<int,double> Graph::getNeighborForNode(int nodeID, int neighborIdx) const {
  return adjList[nodeID][neighborIdx];
}
 
void Graph::printAdjList() const {
  for (unsigned long i = 0; i < adjList.size(); i++) {
    std::cout << "idx of vec node n: " << i << "      ";
    for (auto p : adjList[i]) {
      std::cout << "<" << p.first << ", " << p.second << ">     ";
    }
    std::cout << std::endl;
  }
}