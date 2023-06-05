#pragma once
#include "edge.hpp"
#include "node.hpp"

class Vlucht : public Edge{  
    private:
        static int multiplyCost(int* cost);

    public:
        Vlucht(Node* from, Node* to, int cost);
        std::string getType() override;
};