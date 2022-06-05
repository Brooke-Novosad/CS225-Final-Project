#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "Shortest.h"
#include "TourFinder.h"
#include <vector>
#include <fstream>
int main () {
    Graph g;
    
    //total number of nodes is 1088092
    g.readin("roadNet-PA.txt", 1088092);

    std::ofstream out;
    out.open("output.txt");
    
    //BFS Deliverable
    //The traversal starting from 0 (this will be in "output.txt", it won't be printed in the terminal)
    BFS bfs(&g);
    
    std::vector<int> vis = bfs.getVisitedVector();
    out << "The BFS traversal starting from 0 is: " << std::endl;
    for (unsigned i = 0; i < vis.size(); i++) {
        out << vis.at(i) << ", ";
    }
    out << " " << std::endl;

    //The traversal starting from User input (this will be in "output.txt", it won't be printed in the terminal)
    int bfsstart;
    std::cout << "Type in a starting node for the BFS traversal: " << std::endl;
    std::cin >> bfsstart;
    while (bfsstart < 0 || bfsstart > g.getNumNodes()) {
        std::cout << "Thats not a valid number, pick a new number: " << std::endl;
        std::cin >> bfsstart;
    }
    BFS bfs2(&g, bfsstart);
    
    std::vector<int> vis2 = bfs2.getVisitedVector();
    out << "The BFS traversal starting from " << bfsstart << " is: " << std::endl;
    for (unsigned i = 0; i < vis2.size(); i++) {
        out << vis2.at(i) << ", ";
    }
    out << " " << std::endl;

    //Dijkstra's Deliverable
    //Our Example
    Shortest s1;

    std::pair<double, std::vector<int>> DJ1 = s1.DJ(g, 2, 15);
    std::cout << "The shortest path between 2 and 15 is: " << std::endl;
    out << "The shortest path between 2 and 15 is: " << std::endl;
    for (unsigned i = 0; i < DJ1.second.size(); i++) {
        std::cout << DJ1.second.at(i) << ", ";
        out << DJ1.second.at(i) << ", ";
    }
    std::cout << " " << std::endl;
    std::cout << "The distance of this path is: " << DJ1.first;
    std::cout << " " << std::endl;
    out << " " << std::endl;
    out << "The distance of this path is: " << DJ1.first;
    out << " " << std::endl;

    //User Example
    int s2start;
    int s2end;
    std::cout << "Type in a start node for the shortest path: " << std::endl;
    std::cin >> s2start;
    while (s2start < 0 || s2start > g.getNumNodes()) {
        std::cout << "Thats not a valid number, pick a new number: " << std::endl;
        std::cin >> s2start;
    }
    std::cout << "Type in an end node for the shortest path: " << std::endl;
    std::cin >> s2end;
    while (s2end < 0 || s2end > g.getNumNodes()) {
        std::cout << "Thats not a valid number, pick a new number: " << std::endl;
        std::cin >> s2end;
    }
    Shortest s2;

    std::pair<double, std::vector<int>> DJ2 = s2.DJ(g, s2start, s2end);
    std::cout << "The shortest path between " << s2start << " and " << s2end << " is: " << std::endl;
    out << "The shortest path between " << s2start << " and " << s2end << " is: " << std::endl;
    for (unsigned i = 0; i < DJ2.second.size(); i++) {
        std::cout << DJ2.second.at(i) << ", ";
        out << DJ2.second.at(i) << ", ";
    }
    std::cout << " " << std::endl;
    std::cout << "The distance of this path is: " << DJ2.first;
    std::cout << " " << std::endl;
    out << " " << std::endl;
    out << "The distance of this path is: " << DJ2.first;
    out << " " << std::endl;

    //Tour Finder Deliverable
    //Our Example
    TourFinder f1;

    std::vector<int> TF1 = f1.findTour(g, 5);
    std::cout << "A PA tour starting at 5 is: " << std::endl;
    out << "A PA tour starting at 5 is: " << std::endl;
    for (unsigned i = 0; i < TF1.size(); i++) {
        std::cout << TF1.at(i) << ", ";
        out << TF1.at(i) << ", ";
    }
    std::cout << " " << std::endl;
    out << " " << std::endl;

    //User Example
    int f2start;

    std::cout << "Type in a start node for the tour finder: " << std::endl;
    std::cin >> f2start;
    while (f2start < 0 || f2start > g.getNumNodes()) {
        std::cout << "Thats not a valid number, pick a new number: " << std::endl;
        std::cin >> f2start;
    }
    TourFinder f2;
    std::vector<int> TF2 = f2.findTour(g, f2start);
    std::cout << "A PA tour starting at " << f2start << " is: " << std::endl;
    out << "A PA tour starting at " << f2start << " is: " << std::endl;
    for (unsigned i = 0; i < TF2.size(); i++) {
        std::cout << TF2.at(i) << ", ";
        out << TF2.at(i) << ", ";
    }
    std::cout << " " << std::endl;
    out << " " << std::endl;


/**
    BFS bfs(&g);
    
    std::vector<int> vis = bfs.getVisitedVector();
    std::cout << vis.size() << " vis size " << std::endl;
//    for (unsigned int i = 0; i < 10; i++) {
//        std::cout << vis.at(i) << std::endl;
//    }
    
    BFS bfs2(&g, 6309);
    
    std::vector<int> vis2 = bfs2.getVisitedVector();
    std::cout << vis2.size() << " vis2 size " << std::endl;
//    for (unsigned int i = 0; i < 10; i++) {
//        std::cout << vis2.at(i) << std::endl;
//    }
    // std:: cout << "hi" << std::endl;
    //g.printAdjList();
**/

    return 0;
}