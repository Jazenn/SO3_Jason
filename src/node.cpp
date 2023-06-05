#include <iostream>
#include <string>

#include "include/edge.hpp"


Node::Node(std::string label):label(label){};

std::string Node::getLabel() const{
    return this -> label;
}

std::vector<Node*> Node::findNeighboursOfNode() const{
    std::vector<Node*> neighbouringNodes;
    for(auto edge : Node::edges){
        neighbouringNodes.push_back(edge->getNodeTo());
    }
}

std::ostream &operator<<(std::ostream& os, Node& node) {
    os << "Node " << node.label << "\n";
    return os;
}