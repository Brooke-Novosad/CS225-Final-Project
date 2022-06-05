#include "../cs225/catch/catch.hpp"
#include <iostream>
#include "../BFS.h"

TEST_CASE("Testing default BFS constructor with no starting index. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct number of nodes.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g);
  REQUIRE(bfs.getVisitedNodes().size() == 3);
  REQUIRE(bfs.getVisitedVector().size() == 3);  
  
}

TEST_CASE("Testing BFS constructor with a starting index. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct number of nodes.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g, 2);
  REQUIRE(bfs.getVisitedNodes().size() == 3);
  REQUIRE(bfs.getVisitedVector().size() == 3);
  
}

TEST_CASE("Testing that BFS with a start node added all of the nodes to the traversal. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct order of nodes.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g, 2);
  REQUIRE(bfs.getVisitedVector().at(0) == 2);
  REQUIRE(bfs.getVisitedVector().at(1) == 0);
  REQUIRE(bfs.getVisitedVector().at(2) == 1);
  
}

TEST_CASE("Testing that BFS with a start node visits all of the nodes. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes are marked visited correctly.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g, 2);
  REQUIRE(bfs.getVisitedNodes().at(0) == true);
  REQUIRE(bfs.getVisitedNodes().at(1) == true);
  REQUIRE(bfs.getVisitedNodes().at(2) == true);
  
}

TEST_CASE("Testing that BFS without a start node added all of the nodes to the traversal. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct order of nodes.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g);
  REQUIRE(bfs.getVisitedVector().at(0) == 0);
  REQUIRE(bfs.getVisitedVector().at(1) == 1);
  REQUIRE(bfs.getVisitedVector().at(2) == 2);
  
}

TEST_CASE("Testing that BFS without a start node visits all of the nodes. Connected data set.", "[weight=10][part1]")
{
  // ensuring that the visited nodes are marked visited correctly.
  
  Graph g;
  g.readin("tests/Bfs.txt", 3);
  BFS bfs(&g);
  REQUIRE(bfs.getVisitedNodes().at(0) == true);
  REQUIRE(bfs.getVisitedNodes().at(1) == true);
  REQUIRE(bfs.getVisitedNodes().at(2) == true);
  
}

/*
 * Testing using the unconnected data set. This is important for determining whether or not the BFS helper can deal with nodes that are not connected.
 * 
 */
TEST_CASE("Testing default BFS constructor with no starting index. Unconnected data set", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct number of nodes.
  
  Graph g;
  g.readin("tests/Bfs_Unconnected.txt", 8);
  BFS bfs(&g);
  REQUIRE(bfs.getVisitedNodes().size() == 8);
  REQUIRE(bfs.getVisitedVector().size() == 8);
  
}

TEST_CASE("Testing BFS constructor with a starting index. Unconnected data set", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct number of nodes.
  
  Graph g;
  g.readin("tests/Bfs_Unconnected.txt", 8);
  BFS bfs(&g, 6);
  REQUIRE(bfs.getVisitedNodes().size() == 8);
  REQUIRE(bfs.getVisitedVector().size() == 8);
  
}

TEST_CASE("Testing that BFS with a given start node 6 traverses the graph correctly. Unconnected data set", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct orders of nodes as well as node visited is set to true.
  
  Graph g;
  g.readin("tests/Bfs_Unconnected.txt", 8);
  BFS bfs(&g, 6);
  std::vector<int> expected_traversal = {6,5,0,1,2,4,3,7};
  std::vector<bool> expected_visited(8, true);
  REQUIRE(bfs.getVisitedVector() == expected_traversal);
  REQUIRE(bfs.getVisitedNodes() == expected_visited);
  
}

TEST_CASE("Testing that BFS with a given start node 3 traverses the graph correctly. Unconnected data set", "[weight=10][part1]")
{
    // ensuring that the visited nodes vector is being populated with the correct orders of nodes as well as node visited is set to true.

    Graph g;
    g.readin("tests/Bfs_Unconnected.txt", 8);
    BFS bfs(&g, 3);
    std::vector<int> expected_traversal = {3,1,2,4,0,5,6,7};
    std::vector<bool> expected_visited(8, true);
    REQUIRE(bfs.getVisitedVector() == expected_traversal);
    REQUIRE(bfs.getVisitedNodes() == expected_visited);

}

TEST_CASE("Testing that BFS starting at node 0 traverses the graph correctly. Unconnected data set", "[weight=10][part1]")
{
  // ensuring that the visited nodes vector is being populated with the correct orders of nodes as well as node visited is set to true.
  
  Graph g;
  g.readin("tests/Bfs_Unconnected.txt", 8);
  BFS bfs(&g);
  std::vector<int> expected_traversal = {0,1,2,4,3,5,6,7};
  std::vector<bool> expected_visited(8, true);
  REQUIRE(bfs.getVisitedVector() == expected_traversal);
  REQUIRE(bfs.getVisitedNodes() == expected_visited);
  
}