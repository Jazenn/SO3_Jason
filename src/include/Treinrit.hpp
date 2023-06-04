#pragma once
#include "edge.hpp"

class Treinrit: public Edge{
    private:
        Node* const from;
        Node* const to;
    
    public:
        Treinrit(Node* from, Node* to, int cost);

};