#include "include/graph.hpp"
#include <queue>
#include <map>

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) : nodes(nodes),edges(edges){};

Edge* Graph::getEdgeBetweenNodes(Node* from, Node* to) const{
    for(Edge* edge : from->edges){
        if(edge->getNodeTo() == to){
            return edge;
        }
    }
    return nullptr;
}

int Graph::getCostOfPath(std::vector<Node*> nodesToVisit) const{
    int totalCosts = 0;
    for(int i = 0; i < nodesToVisit.size() -1; i++){
        totalCosts  += getEdgeBetweenNodes(nodesToVisit[i], nodesToVisit[i+1])->cost ;
    }

    //Calculate total costs 
    return totalCosts;
}

std::vector<Node*> Graph::findShortestPathWithDijkstra(Node* start, Node* end) {
    std::priority_queue<Node*, std::vector<Node*>, Node::NodeComparator> pq_nodes;
    pq_nodes.push(start);

    for(Node* node : Graph::nodes){
        if(node->getLabel() == start->getLabel()){
            node->minimalDistance = 0;
        }
        node->minimalDistance = INT_MAX;
    }

    while(size(pq_nodes) != 0){
        Node* n = pq_nodes.top();
        pq_nodes.pop();

        for(Node* neighbour : n->findNeighboursOfNode()){
            int alt = n->minimalDistance + Graph::getCostOfPath(n, neighbour);
        }
    }
}

