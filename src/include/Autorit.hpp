#pragma once
#include "edge.hpp"
#include "node.hpp"

class Autorit : public Edge{  
    private:
        static float multiplyCost(float* cost);

    public:
        Autorit(Node* from, Node* to, float cost);
        std::string getType() override;
        bool operator==(Edge* rhs) const override;
};