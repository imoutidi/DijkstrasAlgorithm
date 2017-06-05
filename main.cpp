//  Implementation of a random graph generator
//  A Priority Queue based on a minHeap
//  And implementation of Dijkstras algorithm on a number of graphs
//  in a Monte Carlo simulation
////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <string>

#include "shortestPath.h"

int main()
{
    // it makes rand() function to give different values each time it is used
    srand (time (NULL));
    double sumavg = 0;
    const int numOfTests = 100;

    // Monte Carlo simulation with node density 20,
    // on a 50 node graph with 10000 iterations
    for (int i = 0; i < numOfTests; i++)
    {
        // it creates a randon graph with node density
        // currentDensity and runs dijkstra algorithm on it
        shortestPath shortP(20);
        shortP.avgOfPaths();
        //  Calculating the average of each graphs average shortest path
        sumavg = sumavg+shortP.getavgPath();
    }

    std::cout << std::string(60, '<') << std::endl;
    std::cout << "The average of the average of the shortest paths" << std::endl
         << "of the graphs with node density 20 and 50 nodes is:"
         << sumavg/numOfTests << std::endl;
    std::cout << std::string(60, '<') << std::endl;
    // Monte Carlo simulation with node density 40,
    // on a 50 node graph with 10000 iterations
    sumavg = 0;
    for (int i = 0; i < numOfTests; i++)
    {
        // it creates a randon graph with node
        // density currentDensity and runs dijkstra algorithm on it
        shortestPath shortP(40);
        shortP.avgOfPaths();
        //  Calculating the average of each graphs average shortest path
        sumavg = sumavg+shortP.getavgPath();
    }
    std::cout << std::endl;
    std::cout << std::string(60, '<') << std::endl;
    std::cout << "The average of the average of the shortest paths" << std::endl
         << "of the graphs with node density 40 and 50 nodes is:"
         << sumavg/numOfTests << std::endl;
    std::cout << std::string(60, '<') << std::endl;
    return 0;
}
