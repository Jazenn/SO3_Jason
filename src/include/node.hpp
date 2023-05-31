#pragma once
#include <string>
#include <iostream>
#include <vector>

class Edge;

class Node
{
private:
    std::string label;
public:
    std::vector<Edge*> edges;

    Node(std::string label);
    std::string Node::getLabel();

    friend std::ostream &operator<<(std::ostream &os, Node& node);
};