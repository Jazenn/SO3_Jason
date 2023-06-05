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

TEST_CASE("Nodes werken met bijbehorende edges.", "node.cpp"){
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