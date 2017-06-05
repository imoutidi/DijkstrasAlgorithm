#include <iostream>
#include <vector>
#include "shortestPath.h"
#include "Graph.h"

    // The dijkstra algorithm is implemented here
    shortestPath::shortestPath(int density)
    {
        int currentNode = 0;
        std::vector <int> visitedNodes;

        // A random graph with is generated with the given density
        Graph randomGraph(density, 1.0, 10.0);
        // Checking if the graph is connected
        if (randomGraph.isConnected() == false) { numberOfNodes = 0; }
        nodeChain.push_back(currentNode);
        //  initialising tempPath
        tempPath.setNodePath(nodeChain);
        tempPath.setTotalWeight(0);
        //  inserting into the queue the first node of the graph
        PQueue.insert(tempPath);
        // inserting the value 9999 to avoid any risk
        // of going out of range in the vector
        visitedNodes.push_back(9999);

        while (allPaths.size() < numberOfNodes)
        {
            // gets the path with the smallest weight from the heap
            try { tempPath = PQueue.deletemin(); }
            // if the node were visited it gets ignored
            catch (std::exception& e) {numberOfNodes = 0; break;}
            try { pivotNode = tempPath.getNodePath().back(); }
            catch (std::exception& e) { numberOfNodes = 0; break; }

            if (notExists(visitedNodes, tempPath.getNodePath().back()))
            {
                visitedNodes.push_back(tempPath.getNodePath().back());
                // stores the current shortest path into allPaths
                allPaths.push_back(tempPath);
                nodeChain = tempPath.getNodePath();
                pivotWeight = tempPath.getTotalWeight();
                // stores the neighbors of the tempPaths last node
                neighNodes = randomGraph.neighbors(
                                                   tempPath.getNodePath().back()
                                                   );
                for (int i = 0; i < neighNodes.size(); i++)
                {
                    // if the node were visited it gets ignored
                    if (notExists(visitedNodes, neighNodes[i].getendNode()))
                    {
                        // gets the neighbor nodes of the current
                        // visited node and adds their path
                        // into the priority queue
                        // using nodechain vector and pivotWeigth variable
                        nodeChain.push_back(neighNodes[i].getendNode());
                        // to assign values to tempPath
                        tempPath.setNodePath(nodeChain);
                        // and tempPath to insert the current
                        // path into the queue
                        pivotWeight = pivotWeight+neighNodes[i].getEdgeWeight();
                        tempPath.setTotalWeight(pivotWeight);
                        PQueue.insert(tempPath);
                        // cleans the nodeChain pivotWeight and
                        // tempPath from the previous values
                        nodeChain.pop_back();
                        tempPath.setNodePath(nodeChain);
                        //  deleting the current neighbor
                        // and current weight to check
                        pivotWeight = pivotWeight-neighNodes[i].getEdgeWeight();
                        //  another neightbor
                        tempPath.setTotalWeight(pivotWeight);
                    }     // second if
                }      // for
            }       // first if
        }         // while
    }
// Checking if the current node have been visited befor e from the algorithm
bool shortestPath::notExists(std::vector<int> vNodes, int node)
{
    //  checks if the current node is inside the given std::vector
    bool check;
    for (int i = 0; i < vNodes.size(); i++)
    {
        check = true;
        if (vNodes[i] == node)
        {
            check = false;
            break;
        }
    }
    return check;
}

//  Calculating the average distance of all the shortests paths of the graph
void shortestPath::avgOfPaths()
{
    for (int i = 0; i < allPaths.size(); i++)
    {
        sumOfPaths = sumOfPaths+allPaths[i].getTotalWeight();
    }
    avgShortestPath = sumOfPaths/(allPaths.size());
    //  if the weight of a path is 0 it gets an estimation of the average
    if (allPaths.size() == 0) {avgShortestPath = 5;}
}

double shortestPath::getavgPath() {return avgShortestPath;}

void shortestPath::displayPaths()
{
    // Displays all the paths that the Dijkstra algorithm calculated
    std::vector <int> currentPath;
    for (int i = 0; i < allPaths.size(); i++)
    {
        // displays the first node of the shortest path for visual reasons "->"
        currentPath = allPaths[i].getNodePath();
        std::cout << currentPath[0]+1;
        for (int j = 1; j < currentPath.size(); j++)
        {
            // displays the rest of the rest of the shortest path with "->"
            std::cout << "->" << currentPath[j]+1;
        }
        std::cout << std::endl;
    }
}

