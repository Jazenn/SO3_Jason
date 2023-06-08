#pragma once
#include "include\vlucht.hpp"

Vlucht::Vlucht(Node* from, Node* to, float cost): Edge(from, to, multiplyCost(&cost)){};

float Vlucht::multiplyCost(float* cost){
    return *cost * 0.75;
}

std::string Vlucht::getType(){
    return "Vlucht";
}

bool Vlucht::operator==(Edge* rhs) const{
    return(this->getNodeFrom() == rhs->getNodeFrom() && this->getNodeTo() == rhs->getNodeTo());
}