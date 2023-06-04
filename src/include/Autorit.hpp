#pragma once
#include "edge.hpp"

class Autorit : public Edge{  
    public:
        Autorit(Node* from, Node* to, int cost);
};