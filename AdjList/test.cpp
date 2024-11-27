#include "AdjList.h"

#include <iostream>

int main() {
    AdjacencyList list = AdjacencyList();
    list.AddVirtex(3);

    list.AddEdge(0, 1, 0);
    list.AddEdge(1, 2, 0);
    list.AddEdge(2, 1, 1);
    list.PrintGraph();
    return 0;
}