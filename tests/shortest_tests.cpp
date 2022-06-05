#include "../cs225/catch/catch.hpp"
#include <iostream>
#include "../Shortest.h"

TEST_CASE("Start and end are the same", "[weight=10][part1]")
{
	Graph g;
    g.readin("tests/ShortestTest.txt", 6);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 3, 3);
	
	REQUIRE(vect.second.size() == 1);
	REQUIRE(vect.second.at(0) == 3);
	REQUIRE(vect.first == 0);
}

TEST_CASE("1 between start and end", "[weight=10][part1]")
{
	Graph g;
    g.readin("tests/weightTest.txt", 5);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 1, 4);
	
	REQUIRE(vect.second.size() == 3);
	REQUIRE(vect.second.at(0) == 1);
	REQUIRE(vect.second.at(1) == 0);
	REQUIRE(vect.second.at(2) == 4);
	REQUIRE(vect.first == 4.5);
}

TEST_CASE("2 paths same distance", "[weight=10][part1]")
{
	Graph g;
    g.readin("tests/ShortestTest.txt", 6);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 3, 0);
	//There are 2 paths between these nodes with the same distance, Dijkstras will pick based on the queue which one is a priority
	
	REQUIRE(vect.second.size() == 3);
	REQUIRE(vect.second.at(0) == 3);
	REQUIRE(vect.second.at(1) == 1);
	REQUIRE(vect.second.at(2) == 0);
	REQUIRE(vect.first == 4.5);
}

TEST_CASE("Bigger 1 distance between nodes", "[weight=10][part1]")
{	
	Graph g;
    g.readin("tests/ShortestTest.txt", 6);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 3, 5);
	
	REQUIRE(vect.second.size() == 5);
	REQUIRE(vect.second.at(0) == 3);
	REQUIRE(vect.second.at(1) == 1);
	REQUIRE(vect.second.at(2) == 0);
	REQUIRE(vect.second.at(3) == 4);
	REQUIRE(vect.second.at(4) == 5);
	REQUIRE(vect.first == 8.5);
}

//tests with a small portion of the data set

TEST_CASE("Bigger distance between nodes with data set", "[weight=10][part1]")
{	
	Graph g;
    g.readin("roadNet-PA.txt", 10);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 2, 9);

	REQUIRE(vect.second.size() == 5);
	REQUIRE(vect.second.at(0) == 2);
	REQUIRE(vect.second.at(1) == 7);
	REQUIRE(vect.second.at(2) == 8);
	REQUIRE(vect.second.at(3) == 5);
	REQUIRE(vect.second.at(4) == 9);
	REQUIRE(vect.first == 9);
}

TEST_CASE("Not connected parts of the graph", "[weight=10][part1]")
{
	Graph g;
    g.readin("roadNet-PA.txt", 10);

	Shortest s;
	std::pair<double, std::vector<int>> vect = s.DJ(g, 1, 2);
	//these 2 nodes aren't connected, distance between them should be inf

	REQUIRE(vect.first == std::numeric_limits<double>::infinity());
}