#include <iostream>
#include <string>
#include <vector>

#include "include\graph.hpp"
#include "include\node.hpp"
#include "include\edge.hpp"

int main(){
    Node nodeA = Node("A");
    Node nodeB = Node("B");
    Node nodeC = Node("C");
    Node nodeD = Node("D");
    Node nodeE = Node("E");
    Node nodeF = Node("F");
    Node nodeG = Node("G");
    Node nodeH = Node("H");

    Edge edge1 = Edge(&nodeA, &nodeB, 5);
    Edge edge2 = Edge(&nodeA, &nodeC, 4);
    Edge edge3 = Edge(&nodeA, &nodeD, 2);
    Edge edge4 = Edge(&nodeB, &nodeE, 1);
    Edge edge5 = Edge(&nodeC, &nodeE, 1);
    Edge edge6 = Edge(&nodeC, &nodeF, 5);
    Edge edge7 = Edge(&nodeC, &nodeD, 6);
    Edge edge8 = Edge(&nodeD, &nodeC, 7);
    Edge edge9 = Edge(&nodeD, &nodeF, 3);
    Edge edge10 = Edge(&nodeE, &nodeC, 2);
    Edge edge11 = Edge(&nodeE, &nodeH, 2);
    Edge edge12 = Edge(&nodeF, &nodeD, 4);
    Edge edge13 = Edge(&nodeF, &nodeG, 5);
    Edge edge14 = Edge(&nodeH, &nodeE, 6);
    Edge edge15 = Edge(&nodeH, &nodeG, 5);
    Edge edge16 = Edge(&nodeG, &nodeH, 1);

    nodeA.edges.insert(nodeA.edges.end(), {&edge1, &edge2, &edge3});
    nodeB.edges.insert(nodeB.edges.end(), {&edge4});
    nodeC.edges.insert(nodeC.edges.end(), {&edge5, &edge6, &edge7});
    nodeD.edges.insert(nodeD.edges.end(), {&edge8, &edge9});
    nodeE.edges.insert(nodeE.edges.end(), {&edge10, &edge11});
    nodeF.edges.insert(nodeF.edges.end(), {&edge12, &edge13});
    nodeG.edges.insert(nodeG.edges.end(), {&edge16});
    nodeH.edges.insert(nodeH.edges.end(), {&edge14, &edge15});

    std::vector<Node*> nodes = {&nodeA, &nodeB, &nodeC, &nodeD, &nodeE, &nodeF, &nodeG, &nodeH};
    std::vector<Edge*> edges = {&edge1, &edge2, &edge3, &edge4, &edge5, &edge6, &edge7, &edge8, 
                                &edge9, &edge10, &edge11, &edge12, &edge13, &edge14, &edge15, &edge16};

    Graph graph1 = Graph(nodes, edges);

    std::cout << "test" << '\n';
    
    for(Edge* edge : nodeA.edges){
        std::cout << *edge << '\n';
    }

    std::cout << "Cost to go from node A to node B: " << graph1.getEdgeBetweenNodes(&nodeA, &nodeB)->cost << '\n';

    std::vector<Node*> nodesVisiting = {&nodeA, &nodeC, &nodeF};
    std::cout << graph1.getCostOfPath(nodesVisiting) << '\n';

    return 0;
}