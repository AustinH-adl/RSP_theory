#include "../AdjList/AdjList.h"
#include "DFS.h"

int main() {
    AdjacencyList list(false);
    
    list.AddVirtex(7);
    
    list.AddEdge(1, 2, false);
    list.AddEdge(1, 5, false);
    list.AddEdge(1, 6, false);
    list.AddEdge(2, 5, false);
    list.AddEdge(2, 3, false);
    list.AddEdge(5, 4, false);
    list.AddEdge(3, 4, false);

    DFS d;

    d.DepthFirstSearch(list, 1);

    return 0;
}