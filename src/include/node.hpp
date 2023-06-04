#pragma once
#include <string>
#include <iostream>
#include <vector>

class Edge;

class Node
{
    private:
        std::string const label;
        
    public:
        std::vector<Edge*> edges;

        int minimalDistance;
        
        Node(std::string label);

        std::string getLabel() const;

        friend std::ostream &operator<<(std::ostream &os, Node& node);

        struct NodeComparator {
            bool operator()(Node* lhs, Node* rhs) {
                return lhs->minimalDistance > rhs->minimalDistance;
        }
    };
};