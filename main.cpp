#include <iostream>
#include <string>
#include <vector>

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
    Treinrit treinrit5 = Treinrit(&nodeF, &nodeG, 5);
    Vlucht vlucht5 = Vlucht(&nodeH, &nodeE, 6);
    Autorit autorit5 = Autorit(&nodeH, &nodeG, 5);
    Autorit autorit6 = Autorit(&nodeG, &nodeH, 1);

    nodeA.edges.insert(nodeA.edges.end(), {&autorit1, &autorit2, &treinrit1});
    nodeB.edges.insert(nodeB.edges.end(), {&treinrit2});
    nodeC.edges.insert(nodeC.edges.end(), {&vlucht1, &autorit3, &autorit4});
    nodeD.edges.insert(nodeD.edges.end(), {&vlucht2, &vlucht3});
    nodeE.edges.insert(nodeE.edges.end(), {&vlucht4, &treinrit3});
    nodeF.edges.insert(nodeF.edges.end(), {&treinrit4, &treinrit5});
    nodeG.edges.insert(nodeG.edges.end(), {&autorit6});
    nodeH.edges.insert(nodeH.edges.end(), {&vlucht5, &autorit5});

    std::vector<Node*> nodes = {&nodeA, &nodeB, &nodeC, &nodeD, &nodeE, &nodeF, &nodeG, &nodeH};
    std::vector<Edge*> edges = {&autorit1, &autorit2, &treinrit1, &treinrit2, &vlucht1, &autorit3, &autorit4, &vlucht2, 
                                &vlucht3, &vlucht4, &treinrit3, &treinrit4, &treinrit5, &vlucht5, &autorit5, &autorit6};

    Graph graph1 = Graph(nodes, edges);

    std::cout << "test" << '\n';
    std::cout << size(nodeA.edges) << '\n';
    
    for(Edge* edge : nodeA.edges){
        std::cout << *edge << '\n';
    }

    std::cout << "Cost to go from node A to node B: " << graph1.getEdgeBetweenNodes(&nodeA, &nodeB)->cost << '\n';

    std::vector<Node*> nodesVisiting = {&nodeA, &nodeC, &nodeF};
    std::cout << graph1.getCostOfPath(nodesVisiting) << '\n';

    // for(Node* node : graph1.findShortestPathWithDijkstra(&nodeA, &nodeF)){
    //     std::cout << node->minimalDistance << node->previousNode << '\n';
    // }

    std::cout << "-------------------------------------" << "\n";
    std::cout << autorit1 << "\n";
    std::cout << graph1.getEdgeBetweenNodes(&nodeA, &nodeB) << "\n";
    std::cout << *graph1.getEdgeBetweenNodes(&nodeA, &nodeB) << "\n";
    std::cout << graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[1]);
    std::cout << *graph1.getEdgeBetweenNodes(graph1.getNodes()[0], graph1.getNodes()[1]);

    std::cout << "-------------------------------------" << "\n";
    std::vector<Node*> neighbouringNodes = nodeA.findNeighboursOfNode();

    for(Node* node : neighbouringNodes){
        std::cout << *node << "\n";
    }
    
    return 0;
}