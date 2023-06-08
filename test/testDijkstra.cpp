#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include\catch.hpp"
#include "..\src\include\graph.hpp"
#include "..\src\include\node.hpp"
#include "..\src\include\edge.hpp"
#include "..\src\include\autorit.hpp"
#include "..\src\include\treinrit.hpp"
#include "..\src\include\vlucht.hpp"

Graph createMockGraph(){
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");
    Node* nodeD = new Node("D");
    Node* nodeE = new Node("E");

    Autorit* autorit1 = new Autorit(nodeA, nodeB, 5);
    Autorit* autorit2 = new Autorit(nodeA, nodeC, 4);
    Treinrit* treinrit1 = new Treinrit(nodeB, nodeD, 2);
    Vlucht* vlucht1 = new Vlucht(nodeC, nodeD, 1);

    nodeA->edges.insert(nodeA->edges.end(), {autorit1, autorit2});
    nodeB->edges.insert(nodeB->edges.end(), {treinrit1});
    nodeC->edges.insert(nodeC->edges.end(), {vlucht1});

    std::vector<Node*> nodes = {nodeA, nodeB, nodeC, nodeD, nodeE};
    std::vector<Edge*> edges = {autorit1, autorit2, treinrit1, vlucht1};

    Graph graph = Graph(nodes, edges);

    return graph;
}

TEST_CASE("Een node wordt correct aangemaakt", "node.cpp"){
    Node node1 = Node("A");
    REQUIRE(node1.getLabel() == "A");
}

TEST_CASE("Nodes werken met bijbehorende edges.", "node.cpp + Edge.cpp"){
    Node nodeA = Node("A");
    Node nodeB = Node("B");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);
    Autorit autorit2 = Autorit(&nodeB, &nodeA, 4);

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1});
    nodeB.edges.insert(nodeB.edges.end(), {&autorit2});

    REQUIRE(size(nodeA.edges) == 1);
    REQUIRE(nodeA.edges.front() == &autorit1);
    REQUIRE(size(nodeB.edges) == 1);
    REQUIRE(nodeB.edges.front() == &autorit2);
}

TEST_CASE("Node kan meerdere edges bevatten.", "node.cpp + Edge.cpp"){
    Node nodeA = Node("A");
    Node nodeB = Node("B");
    Node nodeC = Node("C");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);
    Autorit autorit2 = Autorit(&nodeA, &nodeC, 4);

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1, &autorit2});

    REQUIRE(size(nodeA.edges) == 2);
    REQUIRE(nodeA.edges.front() == &autorit1);
    REQUIRE(nodeA.edges.back() == &autorit2);
    REQUIRE(size(nodeB.edges) == 0);
    REQUIRE(size(nodeC.edges) == 0);
}

TEST_CASE("Nodes werken met verschillende subclasses van Edge", "Node.cpp + Edge.cpp"){
    Node nodeA = Node("A");
    Node nodeB = Node("B");
    Node nodeC = Node("C");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);
    Treinrit treinrit1 = Treinrit(&nodeB, &nodeC, 4);
    Vlucht vlucht1 = Vlucht(&nodeC, &nodeA, 2);

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1});
    nodeB.edges.insert(nodeB.edges.end(), {&treinrit1});
    nodeC.edges.insert(nodeC.edges.end(), {&vlucht1});

    REQUIRE(size(nodeA.edges) == 1);
    REQUIRE(nodeA.edges.front() == &autorit1);
    REQUIRE(size(nodeB.edges) == 1);
    REQUIRE(nodeB.edges.front() == &treinrit1);
    REQUIRE(size(nodeC.edges) == 1);
    REQUIRE(nodeC.edges.front() == &vlucht1);
}

TEST_CASE("A graph is generated correctly", "graph.cpp, node.cpp, edge.cpp"){
    Node nodeA = Node("A");
    Node nodeB = Node("B");
    Node nodeC = Node("C");
    Node nodeD = Node("D");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);
    Autorit autorit2 = Autorit(&nodeA, &nodeC, 4);
    Treinrit treinrit1 = Treinrit(&nodeB, &nodeD, 2);
    Vlucht vlucht1 = Vlucht(&nodeC, &nodeD, 1);\

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1, &autorit2});
    nodeB.edges.insert(nodeB.edges.end(), {&treinrit1});
    nodeC.edges.insert(nodeC.edges.end(), {&vlucht1});

    std::vector<Node*> nodes = {&nodeA, &nodeB, &nodeC, &nodeD};
    std::vector<Edge*> edges = {&autorit1, &autorit2, &treinrit1, &vlucht1};
    Graph graph1 = Graph(nodes, edges);

    std::vector<Node*> testNodes = {&nodeA, &nodeB, &nodeC, &nodeD};
    std::vector<Edge*> testEdges = {&autorit1, &autorit2, &treinrit1, &vlucht1};

    REQUIRE(graph1.getNodes() == testNodes);
    REQUIRE(graph1.getEdges() == testEdges);
}

TEST_CASE("Test whether 2 identical nodes are equal", "node.cpp"){
    Node node1 = Node("A");

    REQUIRE(&node1 == &node1);
}

TEST_CASE("Test whether 2 identical edges are equal", "edge.cpp"){
    Node nodeA = Node("A");
    Node nodeB = Node("B");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);

    REQUIRE(&autorit1 == &autorit1);
}

TEST_CASE("The function getEdgeBetweenNodes works correctly", "graph.cpp, node.cpp, edge.cpp"){
    Graph graph1 = createMockGraph();

    REQUIRE(graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[1]) == graph1.getEdges()[0]);
}

TEST_CASE("The function getEdgeBetweenNodes returns a nullptr when there is no edge between the given nodes", "graph.cpp, node.cpp, edge.cpp"){
    Graph graph1 = createMockGraph();

    REQUIRE(graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[3]) == nullptr);
}

TEST_CASE("The function getCostOfPath works correctly", "graph.cpp, node.cpp, edge.cpp"){
    Graph graph1 = createMockGraph();

    REQUIRE(graph1.getCostOfPath({graph1.getNodes()[0], graph1.getNodes()[1], graph1.getNodes()[3]}) == 11.5);
}

TEST_CASE("The function getCostOfPath returns -1 if path between nodes does not exist.", "graph.cpp, node.cpp, edge.cpp"){
    Graph graph1 = createMockGraph();

    REQUIRE(graph1.getCostOfPath({graph1.getNodes()[0], graph1.getNodes()[4]}) == -1);
}

TEST_CASE("The function findNeighboursOfNode works correctly","node.cpp"){
    Graph graph1 = createMockGraph();
    std::vector<Node*> testingNodes = {graph1.getNodes()[1], graph1.getNodes()[2]};

    REQUIRE(graph1.getNodes()[0]->findNeighboursOfNode() == testingNodes);
}

TEST_CASE("The function findNeighboursOfNode returns an empty vector is node has no neighbours","node.cpp"){
    Graph graph1 = createMockGraph();
    std::vector<Node*> testingNodes = {};

    REQUIRE(graph1.getNodes()[3]->findNeighboursOfNode() == testingNodes);
    REQUIRE(graph1.getNodes()[4]->findNeighboursOfNode() == testingNodes);
}

TEST_CASE("Function findShortestPathWithDijkstra works correctly", "graph.cpp, node.cpp, edge.cpp"){
    Graph graph1 = createMockGraph();
    graph1.findShortestPathWithDijkstra(graph1.getNodes()[0], graph1.getNodes()[3]);
    
    REQUIRE(graph1.getNodes()[3]->minimalDistance == 6.75);
    REQUIRE(graph1.getNodes()[3]->previousNode == graph1.getNodes()[2]);
    REQUIRE(graph1.getNodes()[2]->previousNode == graph1.getNodes()[0]);
}