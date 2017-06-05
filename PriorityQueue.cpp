#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{}
PriorityQueue::~PriorityQueue()
{}
//  inserts an element into the queue
void PriorityQueue::insert(Path element)
{
    heap.push_back(element);
    updateAfterInsert(heap.size() - 1);
}

//  returns the element in the top of the queue and deletes it
Path PriorityQueue::deletemin()
{
    Path min = heap.front();
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    updateAfterDelete(0);
    return min;
}

//  updates the heap after inserting an element
void PriorityQueue::updateAfterInsert(int index)
{
    while ( ( index > 0 ) && ( parent(index) >=  0 ) &&
            ( heap[parent(index)].getTotalWeight()
                > heap[index].getTotalWeight() ) )
    {
        Path tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index);
    }
}

//  updates the heap after deleting an element
void PriorityQueue::updateAfterDelete(int index)
{
    int child = left(index);
    // seeking the right node to place the child
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child].getTotalWeight() >
            heap[right(index)].getTotalWeight() ) )
    {
        child = right(index);
    }
    if ( child > 0 &&
            (heap[child].getTotalWeight() < heap[index].getTotalWeight()))
    {
        Path tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        updateAfterDelete(child);
    }
}

// returns the left child of the parent node, -1 if it hasnt one
int PriorityQueue::left(int parent)
{
    //  2 * parent + 1
    int i = (parent  <<  1) + 1;
    return ( i < heap.size() ) ? i : -1;
}

// returns the right child of the parent node, -1 if it hasnt one
int PriorityQueue::right(int parent)
{
    //  2 * parent + 2
    int i = (parent  <<  1) + 2;
    return (i < heap.size()) ? i : -1;
}

// returns the parent of the child node
int PriorityQueue::parent(int child)
{
    if (child !=  0)
    {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}  //  End of priority queue class
