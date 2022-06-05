#include "TourFinder.h"
#include <vector>
#include <stack>
#include "Shortest.h"

TourFinder::TourFinder() {
    int nodeID_deepest_so_far_ = -1;
    int depth_of_deepest_so_far = -1;
}
  
// returns nodes in the cycle, starting with nodeID
// if cycles does not exist, return empty list
std::vector<int> TourFinder::findTour(const Graph& g, int rootID) {
    
    compute_DFS_tree(g, rootID);
    
    // if the deepest node in the tree that is connencted to the root is the root, no cycle
    if (nodeID_deepest_so_far_ == rootID) {
        // no cycle found
        return std::vector<int>();
    }

    // find path between rootID and nodeID_deepest_so_far in DFS_tree_
    Shortest shortestPathFinder;

    auto pairShortestPath = shortestPathFinder.DJ(DFS_tree_, rootID, nodeID_deepest_so_far_);

    auto path = pairShortestPath.second;

    // add the start node to the end, to show a cycle 
    path.push_back(rootID);

    // can't have a cycle of 3 nodes or less
    if (path.size() <= 3) {
        return std::vector<int>();
    }

    return path;
}

void TourFinder::compute_DFS_tree(const Graph& g, int rootID) {

    std::vector<bool> visited;

    // how far away each node in the tree is from the root
    std::vector<int> steps_away_from_root_;

    unsigned int numNodes = g.getNumNodes();

    // initialize visited and steps away from root
    for (size_t i = 0; i < numNodes; i++) {
        visited.push_back(false);
        steps_away_from_root_.push_back(-1);
    }

    // empty the DFS tree
    Graph temp_graph;
    DFS_tree_ = temp_graph;

    // DFS
    // first one in pair is nodeID, second is parent
    std::stack<std::pair<int, int>> s; 

    // push root onto stack, it has no parent so -1
    s.push(std::pair<int, int>(rootID, -1));

    // root is 0 steps away from itself
    steps_away_from_root_[rootID] = 0;

    while (!s.empty()) {
        std::pair<int, int> exploring = s.top();
        s.pop();

        // if not visited, visit
        if (visited[exploring.first] == false) {
            visited[exploring.first] = true;

            // add to tree
            if (exploring.first != rootID) {
                DFS_tree_.addEdge(exploring.first, exploring.second, 1);
                
                // calculate how far away this node is from the tree using its parent node
                steps_away_from_root_[exploring.first] = steps_away_from_root_[exploring.second] + 1;
            }

            // add all adj nodes 
            unsigned int numNeighbors = g.getNodeDegree(exploring.first);
            for(size_t i = 0; i < numNeighbors; i++) {
                int neighborID = g.getNeighborForNode(exploring.first, i).first;
                s.push(std::pair<int, int>(neighborID, exploring.first));
            }
        }
    }

    // compute deepest node connected to the root with a backedge
    nodeID_deepest_so_far_ = rootID;
    int depth_of_deepest_so_far = 0;
    for (size_t i = 0; i < steps_away_from_root_.size(); i++) {
        bool connected_to_root = g.containsEdge(rootID, i);
        // if deeper than what we've found before & connected to root, new nodeID_deepest_so_far
        if (steps_away_from_root_[i] > depth_of_deepest_so_far && connected_to_root) {
            nodeID_deepest_so_far_ = i;
            depth_of_deepest_so_far = steps_away_from_root_[i];
        }
    }

}