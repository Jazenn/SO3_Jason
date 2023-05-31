#pragma once
#include "node.hpp"

class Edge{
    private:
        Node* const from;
        Node* const to;

    public:
        int cost;

        Edge(Node* from, Node* to, int cost);

        Node* getNodeFrom() const;
        
        Node* getNodeTo() const;

        friend std::ostream &operator<<(std::ostream& os, Edge& edge);
};