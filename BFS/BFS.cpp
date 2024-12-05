#include <queue>
#include <vector>
#include <iostream>
#include "BFS.h"

void BFS::BreadthFirstSearch(AdjacencyList list, int root) {
    std::queue<int> queue;
    int nvirtices = list.getnodes();
    int state[nvirtices];
    int parent[nvirtices];
    for (int i = 0; i < nvirtices; i++) {
        state[i] = UNDISCOVERED;
        parent[i] = -1;
    }
    state[root] = DISCOVERED;
    parent[root] = -1;

    queue.push(root);

    while(!queue.empty()) {
        int curr = queue.front();
        processVirtex(curr);
        for (Edge* e : list.getlist(curr)) {
            if(state[e->virtex]==UNDISCOVERED) {
                state[e->virtex] = DISCOVERED;
                parent[e->virtex] = curr;
                processEdge(e);
                queue.push(e->virtex);
            }
        }
        state[curr] = EXPLORED;
        queue.pop();
    }
}

void BFS::processVirtex(int i)
{
    std::cout << "Virtex " << i << " Discovered. ";
}

void BFS::processEdge(Edge *e)
{
    //std::cout << e->virtex << std::endl;
}
