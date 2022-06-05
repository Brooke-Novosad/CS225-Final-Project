
#pragma once
#include <iostream>
#include <map>
#include <vector>
////#include <pair>


class Graph {

public:
  /**
  * Creates an empty graph, with 0 nodes and 0 edges
  */
  Graph();

  /**
  * Intializes the graph from a file
  * @param filename file in which to read from
  * @param numNodes the amount of nodes you want to have in your list
  */
  void readin(std::string filename, int numNodes);  

  /**
  * Checks if an edge exists between two nodes
  * @param first nodeID of first node
  * @param second nodeID of second node
  * @return true if an edge exists between first and second, false otherwise
  */
  bool containsEdge(int first, int second) const;

  /**
  * Adds an edge between two nodes, creates nodes if not already in the graph
  * @param first nodeID of first node
  * @param second nodeID of second node
  * @param weight weight of edge between first and second
  */
  void addEdge(int first, int second, double weight);

  /**
  * Getter for the number of nodes in the whole graph
  * @return number of nodes in the whole graph
  */
  int getNumNodes() const;

  /**
  * Getter for the degree/number of neighbors a node has
  * @param nodeID nodeID of node to check degree of
  * @return degree nodeID has
  */
  int getNodeDegree(int nodeID) const;

  /**
  * Getter for neighbor's nodeID and weight of edge between two nodes
  * @param nodeID nodeID of first node
  * @param neighborIdx index of nodeID's neighbor
  * @return neighbor's nodeID and the weight of the edge between nodeID and neighbor
  */
  std::pair<int,double> getNeighborForNode(int nodeID, int neighborIdx) const;
  
  
private:


  // index of first vector is node 1, first number in pair is node 2
  // node 1 and 2 have an edge with weight of the second number in the pair
  std::vector<std::vector<std::pair<int, double>>> adjList;

  /**
  * Populates the adjList with weights
  * Weight is sum of the two nodes degrees / 2
  */
  void calculateWeights();
  
  /**
  * Helper function for calculate weights
  * @return vector of calculated degrees for each node, 
  *         nodeID is index in vector and degree is value
  */
  std::vector<double> getDegrees() const;

  /**
  * Helper function for debug, prints the adjList
  */
  void printAdjList() const;
  
};