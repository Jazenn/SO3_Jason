#include "include/edge.hpp"

Edge::Edge(Node* from, Node* to, int cost): from(from), to(to), cost(cost){};

std::ostream &operator<<(std::ostream &os, Edge& edge) {

    os <<  "( " << edge.from->getLabel() << "->" << edge.to->getLabel() << ")" << "\n";
    return os;
}