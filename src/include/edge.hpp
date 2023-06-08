#pragma once
#include "node.hpp"

class Edge{
    private:
        Node* const from;
        Node* const to;

    public:
        float cost;
        
        Edge(Node* from, Node* to, float cost);

        Node* getNodeFrom() const;
        Node* getNodeTo() const;
        virtual std::string getType() = 0;
        virtual bool operator==(Edge* rhs) const = 0;

        friend std::ostream &operator<<(std::ostream& os, Edge& edge);
};