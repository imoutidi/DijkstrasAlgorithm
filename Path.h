#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include <vector>
// Class that contains the sequence of the paths nodes
// and the total weight of the path
class Path{
 public:
void setNodePath(std::vector<int> currentPath);
std::vector<int> getNodePath();
// variable handling
void setTotalWeight(double currentWeight);
double getTotalWeight();

 private:
// stores the nodes of the path
std::vector <int> nodePath;
double totalWeight;
};

#endif // PATH_H_INCLUDED
