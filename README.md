# CS 225 Final Project - Pennsylvania Road Network
**Group Members** 

Eunice Fleung - efleung2

Brooke Novosad - novosad3

Serena Trika - trika2

Jordan Whalen - jwhalen4

## About the Project
Our project uses the Pennsylvania Road Network data set from: https://snap.stanford.edu/data/roadNet-PA.html. This graph is unweighted, undirected, and not connected. It is in the form of a txt file and the data format is Node Node, which represents the edges between these 2 nodes. The nodes are the intersections of roads and the edges are the roads. We wanted to find efficient ways of travel in this project such as the shortest routes and an efficient tours across PA.

## Final Deliverables
Our results paper is in results.md

A video of our final presentation is here: https://youtu.be/c85S64k0IuQ

## How to Use Our Program
To download our program, copy this line into your terminal
```
https://github-dev.cs.illinois.edu/cs225-fa21/jwhalen4-trika2-efleung2-novosad3.git
```
To build the program run 
```
make
```
in the terminal.
Then run
```
./graph
``` 
in the terminal. This will run the code in the main file which are our deliverables and print them to the terminal. In the terminal, it will only print the deliverables for Dijkstra's and the Tour Finder. All deliverables will also print to a file called output.txt.

To run the tests, run 
```
make test
``` 
in the terminal. Then run
```
./test
```
in the terminal. There will be an output in the terminal saying of all tests passed or not.


## Parsing Data
### File: Graph.h/Graph.cpp
Our data was in the form of a txt file (roadNet-PA.txt) as stated above. We decided to use an adjacency list with each list containing pairs of the adjacent node and weight. In this file we had to calculate our weights (**function: calculateWeights()**) and the formula to do this was (degree of node1 + degree of node2) / 2. This simulates that it would take longer to get from one place to another if there were a lot of roads in one intersection meaning someone would have to wait longer for the traffic light to turn green. The main parsing function (**function: readin(std::string filename, int numNodes)**) takes in a file and an int. The int is the number of nodes you want to parse through. This is used for testing with a small dataset from our big data set. This file also has getters for the adjacency list such as **getNumNodes() getNodeDegree(int nodeID), containsEdge(int first, int second), getNeighborForNode(int nodeID, int neighborIdx)**, etc.

## Breadth First Search (BFS Traversal)
### File: BFS.h/BFS.cpp
Our BFS function (**function: BFS(Graph *g, int start)**) takes in a Graph and a starting node. The graph is from the parsing file which contains the adjacency list. The starting node will be where the traversal starts. Calling **getVisitedVector()** will get the vector of the nodes traversed in order.

## Dijkstra's Algorithm
### File: Shortest.h/Shortest.cpp
Our Dijkstra's algorithm function (**function: DJ(Graph g, int start, int end)**) takes in a Graph and a starting and ending node. The graph is from the parsing file which contains the adjacency list. The starting node will be where the path starts from and the ending node will be where the path ends. This returns a pair of vector of ints and a double. The vector is the path of nodes and the double is the length of the shortest path.

## DFS Looking for Deepest Back Edge
### File: TourFinder.h/TourFinder.cpp
Our last Algorithm is a version of a cycle finder. This function (**function: findTour(const Graph& g, int rootID)**)takes in a Graph and a starting node and finds an interesting tour starting at the given node. The graph is from the parsing file which contains the adjacency list. The starting node will be where the tour starts from. This function returns a vector of ints of the nodes in the tour. The first and last nodes of the vector will be the starting node to show a cycle.

