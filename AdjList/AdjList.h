#pragma once
#include <vector>

class Edge {
    friend class AdjacencyList;
    public:
        int weight;
        int virtex;
        Edge(int virtex);
        Edge(int virtex, int weight);
};

class AdjacencyList {
    private:
        std::vector<std::vector<Edge*>> edges;
    protected:
        bool directed;
        int nvertices;
    public:
        AdjacencyList();
        AdjacencyList(bool direct);
        std::vector<Edge*> getlist(int node);
        int getnodes();
        bool AddEdge(int start, int end, bool directed);
        void AddVirtex();
        void AddVirtex(int num);
        void PrintGraph();
        ~AdjacencyList();
};  