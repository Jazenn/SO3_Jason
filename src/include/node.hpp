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
        float minimalDistance;
        Node* previousNode;
        
        Node(std::string label);

        std::string getLabel() const;
        std::vector<Node*> findNeighboursOfNode() const;
        
        friend std::ostream &operator<<(std::ostream &os, Node& node);
        bool operator==(Node* rhs) const;

        struct NodeComparator {
            bool operator()(const Node* lhs, const Node* rhs) const{
                return lhs->minimalDistance > rhs->minimalDistance;
        }
    };
};