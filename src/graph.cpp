#include "include/graph.hpp"
#include <queue>
#include <limits>
#include <tuple>

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) : nodes(nodes),edges(edges){};

std::vector<Node*> Graph::getNodes() const{
    return this->nodes;
}

std::vector<Edge*> Graph::getEdges() const{
    return this->edges;
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
        totalCosts += edgeBetweenNodes->cost ;
    }

    //Calculate total costs 
    return totalCosts;
}

void Graph::findShortestPathWithDijkstra(Node* start, Node* end) {
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

        for(Node* neighbour : n->findNeighboursOfNode()){
            float alt = n->minimalDistance + getCostOfPath({n, neighbour});
            if(alt < neighbour->minimalDistance){
                neighbour->minimalDistance = alt;
                neighbour->previousNode = n;
                pq_nodes.push(neighbour);
            }
        }
    }
}

    std::tuple<int, std::vector<Node*>> getResultsOfDijkstra(Node* start, Node* end){
        std::vector<Node*> dijkstrasPath;
        float totalCost;
        Node* currentNode = end;
        while(currentNode != start){
            totalCost += currentNode->minimalDistance;
            dijkstrasPath.push_back(currentNode);
            currentNode = currentNode->previousNode;
        }
        return std::make_tuple(totalCost, dijkstrasPath);
    }

bool operator==(std::vector<Node*> lhs, std::vector<Node*>rhs){
    if(lhs.size() != rhs.size()){
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

