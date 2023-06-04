#pragma once
#include "edge.hpp"

class Vlucht: public Edge{
    private:
        Node* const from;
        Node* const to;
    
    public:
        Vlucht(Node* from, Node* to, int cost);

};