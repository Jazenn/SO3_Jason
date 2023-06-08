#pragma once
#include "node.hpp"
#include "edge.hpp"
#include <vector>

class Graph{
        private:
            std::vector<Node*> const nodes;
            
            std::vector<Edge*> const edges;

        public:
            Graph(std::vector<Node*> nodes, std::vector<Edge*> edges);

            std::vector<Node*> getNodes() const;
            std::vector<Edge*> getEdges() const;
            Edge* getEdgeBetweenNodes(Node* from, Node* to) const;
            float getCostOfPath(std::vector<Node*> nodesToVisit) const;
            std::vector<Node*> findShortestPathWithDijkstra(Node* start, Node* end);

            friend bool operator==(std::vector<Node*> lhs, std::vector<Node*>rhs);
};