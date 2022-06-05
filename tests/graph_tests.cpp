#include "../cs225/catch/catch.hpp"
#include <iostream>
#include "../Graph.h"

TEST_CASE("Vector populated parsing on small data set", "[weight=10][part1]")
{
    // save graph to the file since we are using the same one for the tests so far 
    // so we dont have to reload it every time? -eunice
    Graph g;
    g.readin("tests/weightTest.txt", 5);

    // check 2d vector correct size in both dimensions
    REQUIRE(g.getNumNodes() == 5);
    REQUIRE(g.getNodeDegree(0) == 2);
    REQUIRE(g.getNodeDegree(1) == 2);
    REQUIRE(g.getNodeDegree(2) == 2);
    REQUIRE(g.getNodeDegree(3) == 3);
    REQUIRE(g.getNodeDegree(4) == 3);
}

TEST_CASE("Parsing calculates weight correctly", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/weightTest.txt", 5);
    
    REQUIRE(g.getNeighborForNode(0,0).second == 2);
    REQUIRE(g.getNeighborForNode(0,1).second == 2.5);
    REQUIRE(g.getNeighborForNode(1,0).second == 2);
    REQUIRE(g.getNeighborForNode(1,1).second == 2.5);
    REQUIRE(g.getNeighborForNode(2,1).second == 2.5);
    REQUIRE(g.getNeighborForNode(3,0).second == 2.5);
    REQUIRE(g.getNeighborForNode(3,1).second == 2.5);
    REQUIRE(g.getNeighborForNode(3,2).second == 3);
    REQUIRE(g.getNeighborForNode(4,0).second == 2.5);
    REQUIRE(g.getNeighborForNode(4,1).second == 2.5);
    REQUIRE(g.getNeighborForNode(4,2).second == 3);
}

TEST_CASE("All adjacent nodes added", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/weightTest.txt", 5);

    REQUIRE(g.getNeighborForNode(0,0).first == 1);
    REQUIRE(g.getNeighborForNode(0,1).first == 4);
    REQUIRE(g.getNeighborForNode(1,0).first == 0);
    REQUIRE(g.getNeighborForNode(1,1).first == 3);
    REQUIRE(g.getNeighborForNode(2,0).first == 4);
    REQUIRE(g.getNeighborForNode(2,1).first == 3);
    REQUIRE(g.getNeighborForNode(3,0).first == 1);
    REQUIRE(g.getNeighborForNode(3,1).first == 2);
    REQUIRE(g.getNeighborForNode(3,2).first == 4);
    REQUIRE(g.getNeighborForNode(4,0).first == 0);
    REQUIRE(g.getNeighborForNode(4,1).first == 2);
    REQUIRE(g.getNeighborForNode(4,2).first == 3);
}

TEST_CASE("Test containsEdge", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/weightTest.txt", 5);

    REQUIRE(g.containsEdge(2,4));
    REQUIRE(!g.containsEdge(10,4));
    REQUIRE(!g.containsEdge(2,2));
    REQUIRE(!g.containsEdge(1,4));
}

TEST_CASE("Test addEdge", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/weightTest.txt", 5);

    g.addEdge(1,4,1);
    REQUIRE(g.containsEdge(1,4));
    REQUIRE(g.containsEdge(4,1));

    g.addEdge(10, 15, 1);
    REQUIRE(g.containsEdge(10,15));
    REQUIRE(g.containsEdge(15,10));
    
    REQUIRE(!g.containsEdge(0,15));
}
