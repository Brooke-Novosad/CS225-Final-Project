CS 225 Final Project Proposal :)  
Trika2  
Novosad3  
Efleung2  
Jwhalen4  
1. Leading Question

    For our final project, we have decided to use a data set of Pennsylvania road routes. This data set has a list of pairs of nodes, indicating an edge between each pair. The edges are unweighted but depending on the algorithms we can calculate the weights of the edges like in Dijkstras. From this dataset we can learn how to get around Pennsylvania, finding paths with the least amount of intersections (shortest path) and finding interesting tours using cycle detection. Our algorithms will allow for a general search tool to find these paths. We are working on helping those in Pennsylvania travel efficiently, as this is a problem everyone faces on a daily basis in their commute. We are also working on helping people explore Pennsylvania in an efficient manner.

2. Dataset Acquisition and Processing 

    We will be using the Pennsylvania Road Network dataset from https://snap.stanford.edu/data/roadNet-PA.html for this final project. One group member can download the data onto their device and upload the data into our github repository. The whole data set is stored in one txt file as two columns of nodes. Each pair of nodes listed implies that there is an edge between the two nodes. There are around 1 million nodes and 1.5 million edges in our dataset. We noticed that each pair of nodes is recorded twice, so when we process the data, we will remove the doubles. To represent the graph, we are thinking of using an adjacency list. This list will store each node as an int as in the txt file. Then each node will have another vector of pairs that store the node and edge connecting it and the weights between these nodes. We will calculate the degrees of the 2 nodes the edge is connecting, then take the average of the 2 and set that equal to the weight. This emulates that if an intersection of a street has multiple roads, the light will take longer to turn taking more time to get to the destination.
    
The errors that will come from data incorrectness which could be caught by exceptions. If the cell is empty, or if it contains the wrong data type, we can either remove the data pair that is incorrect or try to decipher what it was meant to be. For example if our data set is integers but someone entered a string, we could convert it to an integer.


3. Graph Algorithms

    1. We will work on creating a tour finder that, given a node, finds a long cycle starting at that node. If there is no cycle with that node, the function will return an empty list. This function will take in the graph and a starting node of the tour. The output will be a list of ints/node IDs of the tour. We will first implement DFS to find a tree of the whole graph, then find the deepest backedge to the root to find an interesting tour. The run time of DFS to complete this algorithm will be O(E+V). We will then call the shortest path algorithm which is O(ElogV). Overall it is expected to be O(ElogV) since E > V for our dataset.

    2. Find shortest path using Dijkstra’s algorithm
We could expect that this method would take in two nodes. We are expecting this method to return the shortest path between two inputted nodes as a double and the vector of ints containing the nodes of the path, as a pair. We will call in the adjacency list so we can use it in this class. We will have to calculate the distance between each node and the starting node, once it is visited it will have to be marked as visited, because if it is not it could run infinitely, similar to DFS. The running time for this algorithm is dependent upon how we implement it, if we use an array or a min-based priority based queue, according to wikipedia the Big O running time of a min- based priority queue is O((|V| +|E|) log(|V|)) where V is the number of nodes and E is the number of edges.  For an array the Big O is O(|V|^2).

  3. We will be using BFS for our graph traversal. Its input is a starting node and we will use this node to start the traversal. Its output is a vector of the order the nodes were traversed in. Its runtime is O(V + E) as proved in the lecture on November 12.

4. Timeline

* Import data (get our data set into the repo) - Week 1
* Sort through data adjacency list (might change to adjacency matrix later depending on implementation) -Week 1
* Dijkstra’s algorithm implementation (doing the methods listed above) - Week 1
* Shortest path using Dijkstra’s algorithm (using the methods above as well as graph traversals) - Week 2
* Add tests for Dijkstra’s algorithm and shortest path - Week 2 - 3
* Begin BFS traversal - Week 2 - 3
* Tour finder, work on DFS implementation and modifiying Graph to create a DFS tree - Week 2 - 3
* Finish BFS traversal - Week 3
* 2 mains, one for each algorithm (so we are able to differentiate between the 2 methods) - Week 3
* Create README where we describe the project and how to run it - Week 4
* Create video presentation explaining the project - Week 4
* Create final written report - Week 4
* Maybe picture of graph (if time permits) - Week 4
