#pragma once
#include "edge.hpp"
#include "node.hpp"

class Treinrit : public Edge{  
    private:
        static int multiplyCost(int* cost);

    public:
        Treinrit(Node* from, Node* to, int cost);
};