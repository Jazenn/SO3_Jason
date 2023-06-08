#pragma once
#include "include\treinrit.hpp"

Treinrit::Treinrit(Node* from, Node* to, float cost): Edge(from, to, multiplyCost(&cost)){};

float Treinrit::multiplyCost(float* cost){
    return *cost * 2;
}

std::string Treinrit::getType(){
    return "Treinrit";
}

bool Treinrit::operator==(Edge* rhs) const{
    return(getNodeFrom() == rhs->getNodeFrom() && this->getNodeTo() == rhs->getNodeTo());
}