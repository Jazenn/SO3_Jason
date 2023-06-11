#pragma once
#include "include\autorit.hpp"

Autorit::Autorit(Node* from, Node* to, float cost): Edge(from, to, multiplyCost(&cost)){};

float Autorit::multiplyCost(float* cost){
    return *cost * 1.5;
}

std::string Autorit::getType(){
    return "Autorit";
}

bool Autorit::operator==(Edge* rhs) const{
    return(this->getNodeFrom() == rhs->getNodeFrom() && this->getNodeTo() == rhs->getNodeTo());
}