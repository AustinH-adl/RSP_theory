#include "AdjList.h"
#include <iostream>

AdjacencyList::AdjacencyList() {
    nvertices = 0;
    directed = false;
}

AdjacencyList::AdjacencyList(bool direct) {
    this->directed = direct;
    nvertices = 0;
}

std::vector<Edge *> AdjacencyList::getlist(int node)
{
    if(node < nvertices)
        return edges[node];
    
    return {};
}

int AdjacencyList::getnodes()
{
    return nvertices;
}

bool AdjacencyList::AddEdge(int start, int end, bool directed) {
    if ((start > nvertices) || (end > nvertices)) {
        return false;
    } else {
        edges[start].push_back(new Edge(end));
        
        if(!directed) {
            edges[end].push_back(new Edge(start));
        }
    }
    return true;
}

void AdjacencyList::AddVirtex()
{
    std::vector<Edge*> newvirtex;
    this->edges.push_back(newvirtex);
    nvertices++;
}

void AdjacencyList::AddVirtex(int num)
{
    for (int i =0; i < num; i++) {
        std::vector<Edge*> newvirtex;
        this->edges.push_back(newvirtex);
        nvertices++;
    }
}

void AdjacencyList::PrintGraph() {
    int count = 0;
    for(std::vector<Edge*> list : edges) {
            count++;
            std::cout << "Edge " << count << " Connects to: ";
            for(Edge* edge : list) {
                std::cout << edge->virtex << " With Weight: " << edge->weight << "\n";
            }
            std::cout << std::endl;
        }
}

AdjacencyList::~AdjacencyList() {
    for(auto list : edges) {
        list.clear();
        list.shrink_to_fit();
    }
}

Edge::Edge(int virtex) {
    this->virtex = virtex;
    weight = 0;
}