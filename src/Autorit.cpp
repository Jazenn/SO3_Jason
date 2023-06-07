#pragma once
#include "include\autorit.hpp"

Autorit::Autorit(Node* from, Node* to, int cost): Edge(from, to, multiplyCost(&cost)){};

int Autorit::multiplyCost(int* cost){
    return *cost * 1.5;
}

std::string Autorit::getType(){
    return "Autorit";
}

bool Autorit::operator==(Edge* rhs) const{
    return(this->getNodeFrom() == rhs->getNodeFrom() && this->getNodeTo() == rhs->getNodeTo());
}