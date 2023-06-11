#include "include/graph.hpp"
#include <queue>
#include <limits>
#include <tuple>
#include <iostream>
#include <ostream>

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges, std::string pathType) : nodes(nodes),edges(edges), pathType(pathType){};
Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) : nodes(nodes),edges(edges), pathType("None"){};

std::vector<Node*> Graph::getNodes() const{
    return this->nodes;
}

std::vector<Edge*> Graph::getEdges() const{
    return this->edges;
}

std::string Graph::getTypePath() const{
    return this->pathType;
}

Edge* Graph::getEdgeBetweenNodes(Node* from, Node* to) const{
    for(Edge* edge : from->edges){
        if(edge->getNodeTo() == to){
            return edge;
        }
    }
    return nullptr;
}

float Graph::getCostOfPath(std::vector<Node*> nodesToVisit) const{
    float totalCosts = 0;
    for(int i = 0; i < nodesToVisit.size() -1; i++){
        Edge* edgeBetweenNodes = getEdgeBetweenNodes(nodesToVisit[i], nodesToVisit[i+1]);
        if(edgeBetweenNodes == nullptr){
            return -1;
        }
        totalCosts += edgeBetweenNodes->cost;
    }
    //Calculate total costs 
    return totalCosts;
}

void Graph::findShortestPathWithDijkstra(Node* start, Node* end, std::string pathType) {
    std::priority_queue<Node*, std::vector<Node*>, Node::NodeComparator> pq_nodes;
    std::vector<float> distances;
    std::vector<Node*> previous_nodes;

    pq_nodes.push(start);

    for(Node* node : Graph::nodes){
        if(node->getLabel() == start->getLabel()){
            node->minimalDistance = 0;
        }
        else{
            node->minimalDistance = std::numeric_limits<float>::max();
        }
        node->previousNode = nullptr;
    }

    while(!pq_nodes.empty()){
        Node* n = pq_nodes.top();
        pq_nodes.pop();

        for(Node* neighbour : n->findNeighboursOfNode(pathType)){
            float alt = n->minimalDistance + getCostOfPath({n, neighbour});
            if(alt < neighbour->minimalDistance){
                neighbour->minimalDistance = alt;
                neighbour->previousNode = n;
                pq_nodes.push(neighbour);
            }
        }
    }
}

std::tuple<float, std::vector<Node*>> Graph::getResultsOfDijkstra(Node* start, Node* end){
    std::vector<Node*> dijkstrasPath;
    Node* currentNode = end;
    while(currentNode != start){
        dijkstrasPath.push_back(currentNode);
        currentNode = currentNode->previousNode;
    }
    dijkstrasPath.push_back(start);
    return std::make_tuple(end->minimalDistance, dijkstrasPath);
}

bool operator==(std::vector<Node*> lhs, std::vector<Node*>rhs){
    if(lhs.size() != rhs.size()){
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

std::ostream &operator<<(std::ostream &os, const Graph& graph) {
    for(Node* node : graph.getNodes()){
        os << "Node " << node->getLabel() << ":" << "\n";
        for (const Edge* edge : node->edges) {
            os << "Edge (" << node->getLabel() << " -> " << edge->getNodeTo()->getLabel() << "): "
            << edge->cost << "\n";
        }
        os << "\n";
    }
    return os;
}

