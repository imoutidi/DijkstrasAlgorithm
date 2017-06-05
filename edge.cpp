#include "edge.h"

//edge::edge(){startNode=0; endNode=0; edgeWeight=0;}
int edge::getstartNode() {return startNode;}
void edge::setstartNode(int numOfNode) {startNode = numOfNode;}
int edge::getendNode() {return endNode;}

// handling functions
void edge::setendNode(int numOfNode) {endNode = numOfNode;}
double edge::getEdgeWeight() {return edgeWeight;}
void edge::setEdgeWeight(double valueOfWeight) {edgeWeight = valueOfWeight;}
