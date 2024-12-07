#include "DFS.h"
#include <iostream>

void DFS::DepthFirstSearch(AdjacencyList list, int root) {
    int discovered[list.getnodes()] = {UNDISCOVERED};

    RecurseiveDFS(list, root, discovered);
}

void DFS::RecurseiveDFS(AdjacencyList list, int virtex, int discovered[]) {
    if (discovered[virtex] < 1) {
        discovered[virtex] = DISCOVERED;
    }
    processVirtex(virtex);
    for(auto i : list.getlist(virtex)) {
        if(discovered[i->virtex] < 1) {
            processEdge(i);
            RecurseiveDFS(list, i->virtex, discovered);
        }
    }
    discovered[virtex] = EXPLORED;
    return;
}

void DFS::processVirtex(int i)
{
    std::cout << i << std::endl;
}

void DFS::processEdge(Edge *e)
{
    return;
}
