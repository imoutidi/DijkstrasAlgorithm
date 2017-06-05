#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <cstdlib>
#include "edge.h"

class Graph {
 private:
// here will be stored all the info (edges,nodes) of the graph
std::vector <std::vector <edge> > edgelist;
// pivot variable which hold a random calculated number to use it
// for the density check
int randDensity;
// max,min will be used for selecting a random value between 1-100
const int max = 100;
const int min = 1;
const int NumOfNodes = 50;
double temp, randomDouble;

 public:
Graph();
Graph(int density, double minWeightRange, double maxWeightRange);
~Graph();
// returns the number of verticies in the Graph
int Vertices();
// returns the number of edges of the graph
int NumOfEdges();
// returns true if the nodes are connected false if they are not
bool adjacent(int node1, int node2);
//  returns a std::vector of the neighbors of node x
std::vector<edge> neighbors(int node);
// helping function to display the graphs edge list in "1->2->6"
void GraphDisplay();
// Checks if the graph is connected with every node
bool isConnected();
};  //  End of Graph class

#endif // GRAPH_H_INCLUDED
