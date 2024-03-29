#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#include "src\include\graph.hpp"
#include "src\include\node.hpp"
#include "src\include\edge.hpp"
#include "src\include\autorit.hpp"
#include "src\include\treinrit.hpp"
#include "src\include\vlucht.hpp"

int main(){
    Node nodeA = Node("A");
    Node nodeB = Node("B");
    Node nodeC = Node("C");
    Node nodeD = Node("D");
    Node nodeE = Node("E");
    Node nodeF = Node("F");
    Node nodeG = Node("G");
    Node nodeH = Node("H");

    Autorit autorit1 = Autorit(&nodeA, &nodeB, 5);
    Autorit autorit2 = Autorit(&nodeA, &nodeC, 4);
    Treinrit treinrit1 = Treinrit(&nodeA, &nodeD, 2);
    Treinrit treinrit2 = Treinrit(&nodeB, &nodeE, 1);
    Vlucht vlucht1 = Vlucht(&nodeC, &nodeE, 1);
    Autorit autorit3 = Autorit(&nodeC, &nodeF, 5);
    Autorit autorit4 = Autorit(&nodeC, &nodeD, 6);
    Vlucht vlucht2 = Vlucht(&nodeD, &nodeC, 7);
    Vlucht vlucht3 = Vlucht(&nodeD, &nodeF, 3);
    Vlucht vlucht4 = Vlucht(&nodeE, &nodeC, 2);
    Treinrit treinrit3 = Treinrit(&nodeE, &nodeH, 2);
    Treinrit treinrit4 = Treinrit(&nodeF, &nodeD, 4);
    Autorit autorit5 = Autorit(&nodeF, &nodeG, 5);
    Vlucht vlucht5 = Vlucht(&nodeH, &nodeE, 6);
    Autorit autorit6 = Autorit(&nodeH, &nodeG, 5);
    Autorit autorit7 = Autorit(&nodeG, &nodeH, 1);

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1, &autorit2, &treinrit1});
    nodeB.edges.insert(nodeB.edges.end(), {&treinrit2});
    nodeC.edges.insert(nodeC.edges.end(), {&vlucht1, &autorit3, &autorit4});
    nodeD.edges.insert(nodeD.edges.end(), {&vlucht2, &vlucht3});
    nodeE.edges.insert(nodeE.edges.end(), {&vlucht4, &treinrit3});
    nodeF.edges.insert(nodeF.edges.end(), {&treinrit4, &autorit5});
    nodeG.edges.insert(nodeG.edges.end(), {&autorit7});
    nodeH.edges.insert(nodeH.edges.end(), {&vlucht5, &autorit6});

    std::vector<Node*> nodes = {&nodeA, &nodeB, &nodeC, &nodeD, &nodeE, &nodeF, &nodeG, &nodeH};
    std::vector<Edge*> edges = {&autorit1, &autorit2, &treinrit1, &treinrit2, &vlucht1, &autorit3, &autorit4, &vlucht2, 
                                &vlucht3, &vlucht4, &treinrit3, &treinrit4, &autorit5, &vlucht5, &autorit6, &autorit7};

    Graph graph1 = Graph(nodes, edges);

    // std::cout << "test" << '\n';
    // std::cout << size(nodeA.edges) << '\n';
    
    // for(Edge* edge : nodeA.edges){
    //     std::cout << *edge << '\n';
    // }

    // std::cout << "Cost to go from node A to node B: " << graph1.getEdgeBetweenNodes(&nodeA, &nodeB)->cost << '\n';

    // std::vector<Node*> nodesVisiting = {&nodeA, &nodeC, &nodeF};
    // std::cout << graph1.getCostOfPath(nodesVisiting) << '\n';

    // // for(Node* node : graph1.findShortestPathWithDijkstra(&nodeA, &nodeF)){
    // //     std::cout << node->minimalDistance << node->previousNode << '\n';
    // // }

    // std::cout << "-------------------------------------" << "\n";
    // std::cout << autorit1 << "\n";
    // std::cout << graph1.getEdgeBetweenNodes(&nodeA, &nodeB) << "\n";
    // std::cout << *graph1.getEdgeBetweenNodes(&nodeA, &nodeB) << "\n";
    // std::cout << graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[1]);
    // std::cout << *graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[1]);

    // std::cout << "-------------------------------------" << "\n";
    // std::vector<Node*> neighbouringNodes = nodeA.findNeighboursOfNode();

    // for(Node* node : neighbouringNodes){
    //     std::cout << *node << "\n";
    // }

    // std::cout << "-------------------------------------" << "\n";
    // std::cout << "DIJKSTRA'S ALGORITHM TESTING" << "\n";

    // graph1.findShortestPathWithDijkstra(graph1.getNodes()[0], graph1.getNodes()[3]);

    // for (Node* node : nodes) {
    // std::cout << "Minimal distance to " << node->getLabel() << ": " << node->minimalDistance << "\n";
    // if (node->previousNode) {
    //     std::cout << "Previous node: " << node->previousNode->getLabel() << "\n";
    // } else {
    //     std::cout << "Previous node: None\n";
    // }
    // std::cout << "\n";
// }
    std::cout << "Welkom bij deze demo van het Dijkstra algoritme!" << "\n";
    std::cout << "Dit is een voorbeeld graaf die we hebben aangemaakt:" << "\n";
    std::cout << graph1 << "\n";

    std::cout << "Nu gaan we het kortste pad vinden tussen 2 nodes, laten we makkelijk beginnen met Node A en B." << "\n";
    graph1.findShortestPathWithDijkstra(graph1.getNodes()[0], graph1.getNodes()[1], graph1.getTypePath());
    std::tuple<float, std::vector<Node*>> results1 = graph1.getResultsOfDijkstra(graph1.getNodes()[0], graph1.getNodes()[1]);
    std::cout << "Het kortste pad tussen deze nodes is: " << std::get<0>(results1) << ", met het volgende pad:" << "\n";
    std::reverse(std::get<1>(results1).begin(), std::get<1>(results1).end());
    for(Node* node : std::get<1>(results1)){
        std::cout << *node << " -> ";
    }
    std::cout << "Done!";
    std::cout << "\n" << "\n";

    std::cout << "Laten we nu een iets moeilijker voorbeeld pakken, namelijk Node A en Node H." << "\n";
    graph1.findShortestPathWithDijkstra(graph1.getNodes()[0], graph1.getNodes()[7], graph1.getTypePath());
    std::tuple<float, std::vector<Node*>> results2 = graph1.getResultsOfDijkstra(graph1.getNodes()[0], graph1.getNodes()[7]);
    std::cout << "Het kortste pad tussen deze nodes is: " << std::get<0>(results2) << ", met het volgende pad:" << "\n";
    std::reverse(std::get<1>(results2).begin(), std::get<1>(results2).end());
    for(Node* node : std::get<1>(results2)){
        std::cout << *node << " -> ";
    }
    std::cout << "Done!";
    std::cout << "\n" << "\n";

    std::cout << "Laten we nu nog een laatste voorbeeld erbij pakken, waarbij er een manier van transporteren wordt meegegeven," <<
                 " zodat alleen edges met dit type transportatie kunnen worden gebruikt.";
    Graph graph2 = Graph(nodes, edges, "Autorit");

    std::cout << " We beginnen weer makkelijk, met Node A en B." << "\n";
    graph2.findShortestPathWithDijkstra(graph2.getNodes()[0], graph1.getNodes()[1], graph2.getTypePath());
    std::tuple<float, std::vector<Node*>> results3 = graph2.getResultsOfDijkstra(graph2.getNodes()[0], graph2.getNodes()[1]);
    std::cout << "Het kortste pad tussen deze nodes is: " << std::get<0>(results3) << ", met het volgende pad:" << "\n";
    std::reverse(std::get<1>(results3).begin(), std::get<1>(results3).end());
    for(Node* node : std::get<1>(results3)){
        std::cout << *node << " -> ";
    }
    std::cout << "Done!";
    std::cout << "\n" << "\n";
    
    std::cout << "Als we nu een moeilijker voorbeeld pakken, zoals van Node A naar node H:" << "\n";
    graph2.findShortestPathWithDijkstra(graph2.getNodes()[0], graph2.getNodes()[7], graph2.getTypePath());
    std::tuple<float, std::vector<Node*>> results4 = graph2.getResultsOfDijkstra(graph2.getNodes()[0], graph2.getNodes()[7]);
    std::cout << "Het kortste pad tussen deze nodes is: " << std::get<0>(results4) << ", met het volgende pad:" << "\n";
    std::reverse(std::get<1>(results4).begin(), std::get<1>(results4).end());
    for(Node* node : std::get<1>(results4)){
        std::cout << *node << " -> ";
    }
    std::cout << "Done!";
    std::cout << "\n" << "\n";
    std::cout << "Nu moet het algoritme een langere route kiezen, om te voldoen aan de eisen." << "\n" << "\n" << "\n";

    std::cout << "Zoals u kunt zien, werkt dit algoritme naar behoren. Bedankt voor het kijken naar deze demo!" << "\n" << "\n";

    return 0;
}