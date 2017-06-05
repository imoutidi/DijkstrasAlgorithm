#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

// can be used for directed and undirected graphs
class edge{
 private:
 // the node that the edge starts
int startNode;
// the node that the edge goes
int endNode;
// the weight of the edge connecting the current neighbor
double edgeWeight;

 public:
//edge(){}
int getstartNode();
void setstartNode(int numOfNode);
int getendNode();

// handling functions
void setendNode(int numOfNode);
double getEdgeWeight();
void setEdgeWeight(double valueOfWeight);
};  //  End of edge class

#endif // EDGE_H_INCLUDED
