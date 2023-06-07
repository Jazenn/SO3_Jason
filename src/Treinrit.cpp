#pragma once
#include "include\treinrit.hpp"

Treinrit::Treinrit(Node* from, Node* to, int cost): Edge(from, to, multiplyCost(&cost)){};

int Treinrit::multiplyCost(int* cost){
    return *cost * 2;
}

std::string Treinrit::getType(){
    return "Treinrit";
}

bool Treinrit::operator==(Edge* rhs) const{
    return(getNodeFrom() == rhs->getNodeFrom() && this->getNodeTo() == rhs->getNodeTo());
}