#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "Path.h"
//  Implementing the priority queue using a minHeap
class PriorityQueue {
 public:
    PriorityQueue();
    ~PriorityQueue();
    //  inserts an element into the queue
    void insert(Path element);
    //  returns the element in the top of the queue and deletes it
    Path deletemin();
    void print();
    //  returns the size of the queue
    int size() { return heap.size(); }

 private:
    //  returns the left child of the parent node
    int left(int parent);
    //  returns the right child of the parent node
    int right(int parent);
    //  returns the parent of the given child node
    int parent(int child);
    //  updates the heap after inserting an element
    void updateAfterInsert(int index);
    //  updates the heap after deleting an element
    void updateAfterDelete(int index);
    //  contains the nodes of the heap
    std::vector<Path> heap;
};

#endif // PRIORITYQUEUE_H_INCLUDED
