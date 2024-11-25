#include "Graph.h"

// GraphNode constructor
GraphNode::GraphNode() : island_number(-1) {}

// Graph constructor
Graph::Graph(int numNodes, int numIslands, int islandID) {
    for (int i = 0; i < numNodes; i++) {
        GraphNode newNode;
        std::cout << "Enter name: ";
        std::cin >> newNode.name;
        std::cout << "Enter identity: ";
        std::cin >> newNode.identity;
        newNode.island_number = islandID;
        nodes.push_back(newNode);
    }

    adj_list.resize(numNodes, std::vector<int>(numNodes, -1));
    islands.resize(numIslands, 0);

    std::cout << "Enter adjacency matrix: \n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            std::cin >> adj_list[i][j];
        }
    }
}

// Add a new node
void Graph::addNode() {
    // Implementation goes here
}

// Print graph
void Graph::printGraph() {
    for (const auto& node : nodes) {
        std::cout << node.name << " (" << node.island_number << "): " << node.identity << std::endl;
    }
    for (const auto& row : adj_list) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
