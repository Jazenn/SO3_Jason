#include "include/node.hpp"

Node::Node(std::string label):label(label){};

Node::getLabel() const{
    return this -> label;
}

std::ostream &operator<<(std::ostream& os, Node& node) {
    os << "Node " << node.label << "\n";
    return os;
}