#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include\catch.hpp"
#include "..\src\include\graph.hpp"
#include "..\src\include\node.hpp"
#include "..\src\include\edge.hpp"
#include "..\src\include\autorit.hpp"
#include "..\src\include\treinrit.hpp"
#include "..\src\include\vlucht.hpp"

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