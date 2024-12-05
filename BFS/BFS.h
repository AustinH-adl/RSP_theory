#pragma once

#include "../AdjList/AdjList.h"

#define UNDISCOVERED 0
#define DISCOVERED 1
#define EXPLORED 2

class BFS {
    public:
        void BreadthFirstSearch(AdjacencyList list, int root);
        void processVirtex(int i);
        void processEdge(Edge* e);
};