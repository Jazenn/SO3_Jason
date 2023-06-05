#pragma once
#include "include\vlucht.hpp"

Vlucht::Vlucht(Node* from, Node* to, int cost): Edge(from, to, multiplyCost(&cost)){};

int Vlucht::multiplyCost(int* cost){
    return *cost * 0.75;
}

std::string Vlucht::getType(){
    return "Vlucht";
}