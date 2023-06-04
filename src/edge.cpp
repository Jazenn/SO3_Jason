#include "include/edge.hpp"

Edge::Edge(Node* from, Node* to, int cost): from(from), to(to), cost(cost){};

Node* Edge::getNodeFrom() const{
    return this -> from;
}

Node* Edge::getNodeTo() const{
    return this -> to;
}

std::ostream &operator<<(std::ostream &os, Edge& edge) {

    os <<  "(" << edge.from->getLabel() << "->" << edge.to->getLabel() << ")" << ", cost: " << edge.cost << "\n";
    return os;
}