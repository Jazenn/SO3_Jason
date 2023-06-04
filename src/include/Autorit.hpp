#pragma once
#include "edge.hpp"
#include "node.hpp"

class Autorit : public Edge{  
    private:
        static int multiplyCost(int* cost);

    public:
        Autorit(Node* from, Node* to, int cost);
};