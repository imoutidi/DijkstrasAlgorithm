#include <iostream>
#include "Graph.h"
#include "edge.h"


Graph::Graph() {}
Graph::Graph(int density, double minWeightRange, double maxWeightRange)
{
     // temp object that will help to store data for each edge
     edge tempEdge;
    for (int i = 0; i < NumOfNodes; i++)
    {
        edgelist.push_back(std::vector<edge>());       // add an empty row
    }

    for (int i = 0; i < NumOfNodes; i++)
    {
        for (int j = i+1; j < NumOfNodes; j++)
        {
            // stores a random number from 1-100
            randDensity = rand()%(max-min + 1) + min;
            //  if the number is smaller than the given density
            if (randDensity <= density)
            {
                //  the current edge is inserted into the graph
                tempEdge.setendNode(j);
                tempEdge.setstartNode(i);
                temp = static_cast<double>(rand()) / RAND_MAX;
                // gives to temp a random double value
                randomDouble = minWeightRange +
                    temp * (maxWeightRange - minWeightRange);

                // the random value is the weight of the edge
                tempEdge.setEdgeWeight(randomDouble);
                edgelist[i].push_back(tempEdge);
                // stores the edges to the graph
                tempEdge.setendNode(i);
                // because the graph is undirected each edge is stored twice
                tempEdge.setstartNode(j);
                edgelist[j].push_back(tempEdge);
            }
        }
    }
}

Graph::~Graph() {}
// returns the number of verticies in the Graph
int Graph::Vertices() {return NumOfNodes;}
// returns the number of edges of the graph
int Graph::NumOfEdges()
{
    int edgeSum = 0;
    for (int i = 0; i < edgelist.size(); i++)
    {
        edgeSum +=  edgelist[i].size();
    }

    return edgeSum / 2;
}
// returns true if the nodes are connected false if they are not
bool Graph::adjacent(int node1, int node2)
{
    bool connected = false;
    std::vector <edge> neighborList;
    neighborList  =  neighbors(node1);
    // it stores in the vector neighborList
    // all the nodes that are neighbors to node1
    // checks if node2 is into that std::vector
    for (int i = 0; i < neighborList.size(); i++)
    {
         // and checks if node2 is into that vector
         if (node2  ==  neighborList[i].getendNode())
             connected = true;
    }
    return connected;
}
//  returns a std::vector of the neighbors of node x
std::vector<edge> Graph::neighbors(int node)
{
    std::vector<edge> neighborList;
    neighborList = edgelist[node];

    return neighborList;
}
// helping function to display the graphs edge list in "1->2->6"
void Graph::GraphDisplay()
{
    for (int i = 0; i < edgelist.size(); i++)
    {
        std::cout << i+1;
        for (int j = 0; j < edgelist[i].size(); j++)
        {
            std::cout << "->"
                << edgelist[i].at(j).getendNode()+1
                << "("
                << edgelist[i].at(j).getEdgeWeight()
                << ")"
                << " ";
        }
        std::cout << std::endl;
    }
}
// Checks if the graph is connected with every node
bool Graph::isConnected()
{
    bool check = true;
    for (int i = 0; i < edgelist.size(); i++)
    {
        if (edgelist[i].size() == 0)
            check = false;
    }
    return check;
}
