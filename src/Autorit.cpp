#pragma once
#include "include\autorit.hpp"

Autorit::Autorit(Node* from, Node* to, int cost): Edge(from, to, multiplyCost(&cost)){};

int Autorit::multiplyCost(int* cost){
    return *cost * 1.5;
}

std::string getType(){
    return "Autorit";
}