#pragma once

#include "../AdjList/AdjList.h"

#define UNDISCOVERED 0
#define DISCOVERED 1
#define EXPLORED 2

class DFS {
    public:
    void DepthFirstSearch(AdjacencyList list, int root);
    private:
    void RecurseiveDFS(AdjacencyList list, int virtex, int discovered[]);
    void processVirtex(int i);
    void processEdge(Edge* e);
};