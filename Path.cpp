#include <vector>
#include "Path.h"

void Path::setNodePath(std::vector<int> currentPath) {nodePath = currentPath;}
std::vector<int> Path::getNodePath() {return nodePath;}
// variable handling
void Path::setTotalWeight(double currentWeight) {totalWeight = currentWeight;}
double Path::getTotalWeight() {return totalWeight;}

