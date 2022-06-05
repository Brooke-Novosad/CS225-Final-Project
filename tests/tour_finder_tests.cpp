#include "../cs225/catch/catch.hpp"
#include <iostream>
#include "../Graph.h"
#include "../TourFinder.h"
#include "../Shortest.h"

TEST_CASE("Test small tour finder multiple cycles", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/weightTest.txt", 5);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 4);

    REQUIRE(tour.size() == 5);
    REQUIRE(tour.at(0) == 4);
    REQUIRE(tour.at(1) == 3);
    REQUIRE(tour.at(2) == 1);
    REQUIRE(tour.at(3) == 0);
    REQUIRE(tour.at(4) == 4);
}

TEST_CASE("Test small tour finder one possible cycle", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/ShortestTest.txt", 6);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 3);

    REQUIRE(tour.size() == 5);
    REQUIRE(tour.at(0) == 3);
    REQUIRE(tour.at(1) == 2);
    REQUIRE(tour.at(2) == 0);
    REQUIRE(tour.at(3) == 1);
    REQUIRE(tour.at(4) == 3);
}


TEST_CASE("Test small tour finder disconnected graph", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/ShortestTest.txt", 6);

    g.addEdge(6,7,1);
    g.addEdge(7,8,1);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 3);

    REQUIRE(tour.size() == 5);
    REQUIRE(tour.at(0) == 3);
    REQUIRE(tour.at(1) == 2);
    REQUIRE(tour.at(2) == 0);
    REQUIRE(tour.at(3) == 1);
    REQUIRE(tour.at(4) == 3);
}

TEST_CASE("Test small tour finder no cycle in whole graph", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/tourFinderNoCycle.txt", 8);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 3);

    REQUIRE(tour.size() == 0);
}

TEST_CASE("Test small tour finder no cycle with given node but cycles elsewhere", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/tourFinderNoCycle.txt", 8);

    g.addEdge(4, 6, 1);
    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 1);

    REQUIRE(tour.size() == 0);
}

TEST_CASE("Test small tour finder cycle of 4 (smallest possible cycle)", "[weight=10][part1]")
{
    Graph g;
    g.readin("tests/tourFinderNoCycle.txt", 8);

    g.addEdge(4, 6, 1);
    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 3);

    REQUIRE(tour.size() == 4);
    REQUIRE(tour.at(0) == 3);
    REQUIRE(tour.at(1) == 4);
    REQUIRE(tour.at(2) == 6);
    REQUIRE(tour.at(3) == 3);
    
    tour = tf.findTour(g, 6);

    REQUIRE(tour.size() == 4);
    REQUIRE(tour.at(0) == 6);
    REQUIRE(tour.at(1) == 4);
    REQUIRE(tour.at(2) == 3);
    REQUIRE(tour.at(3) == 6);

    tour = tf.findTour(g, 4);

    REQUIRE(tour.size() == 4);
    REQUIRE(tour.at(0) == 4);
    REQUIRE(tour.at(1) == 6);
    REQUIRE(tour.at(2) == 3);
    REQUIRE(tour.at(3) == 4);
}

TEST_CASE("Test road net PA no cycle", "[weight=10][part1]")
{
    Graph g;
    g.readin("roadNet-PA.txt", 1088092);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 1);
    REQUIRE(tour.size() == 0);
}

TEST_CASE("Test road net PA large cycle", "[weight=10][part1]")
{
    Graph g;
    g.readin("roadNet-PA.txt", 1088092);

    TourFinder tf; 
    std::vector<int> tour = tf.findTour(g, 18);
    REQUIRE(tour.size() != 0);
}
