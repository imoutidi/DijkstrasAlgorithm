#ifndef SHORTESTPATH_H_INCLUDED
#define SHORTESTPATH_H_INCLUDED

#include <vector>
#include "Path.h"
#include "PriorityQueue.h"
#include "edge.h"

class shortestPath {
 private:
    int pivotNode = 0;
    double pivotWeight = 0;
    //  the sum of all shortests paths of one graph
    double sumOfPaths = 0;
    //  the average shortest path of one graph
    double avgShortestPath = 0;
    //  the average of the averages of all graphs
    double avgavgShortestPath = 0;
    int numberOfNodes = 50;
    //  here will be stored all the shortest paths of the graph
    std::vector<Path> allPaths;
    //  the priority queue where the candidate paths will be kept
    PriorityQueue PQueue;
    //  pivot path object
    Path tempPath;
    //  pivot std::vector to tempory store candidate paths
    std::vector<int> nodeChain;
    // vector of edges where the neighbors of the current node will be kept
    std::vector<edge> neighNodes;

 public:
    // The dijkstra algorithm is implemented here
    shortestPath(int density);
// Checking if the current node have been visited befor e from the algorithm
bool notExists(std::vector<int> vNodes, int node);
//  Calculating the average distance of all the shortests paths of the graph
void avgOfPaths();

double getavgPath();
// Displays all the paths that the Dijkstra algorithm calculated
void displayPaths();

};



#endif // SHORTESTPATH_H_INCLUDED
