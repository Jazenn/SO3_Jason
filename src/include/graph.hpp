#pragma once
#include "node.hpp"
#include "edge.hpp"
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>

class Graph{
        private:
            std::vector<Node*> const nodes;
            std::vector<Edge*> const edges;
            std::string pathType;

        public:
            Graph(std::vector<Node*> nodes, std::vector<Edge*> edges, std::string pathType);
            Graph(std::vector<Node*> nodes, std::vector<Edge*> edges);

            std::vector<Node*> getNodes() const;
            std::vector<Edge*> getEdges() const;
            std::string getTypePath() const;
            Edge* getEdgeBetweenNodes(Node* from, Node* to) const;
            float getCostOfPath(std::vector<Node*> nodesToVisit) const;
            void findShortestPathWithDijkstra(Node* start, Node* end, std::string pathType);
            std::tuple<float, std::vector<Node*>> getResultsOfDijkstra(Node* start, Node* end);

            friend bool operator==(std::vector<Node*> lhs, std::vector<Node*>rhs);
            friend std::ostream &operator<<(std::ostream &os, const Graph& graph);
};