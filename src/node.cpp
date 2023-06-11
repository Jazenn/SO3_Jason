#include <iostream>
#include <string>

#include "include/edge.hpp"


Node::Node(std::string label):label(label){};

std::string Node::getLabel() const{
    return this -> label;
}

std::vector<Node*> Node::findNeighboursOfNode(std::string typePath) const{
    std::vector<Node*> neighbouringNodes;
    for(auto edge : Node::edges){
        if(typePath == "None" || edge->getType() == typePath){
            neighbouringNodes.push_back(edge->getNodeTo());
        }
    }
    return neighbouringNodes;
}

std::ostream &operator<<(std::ostream& os, Node& node) {
    os << "Node " << node.label;
    return os;
}

bool Node::operator==(Node* rhs) const{
    return this->getLabel() == rhs->getLabel();
}