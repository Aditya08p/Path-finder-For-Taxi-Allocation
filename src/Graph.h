#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <limits>

class GraphNode {
public:
    std::string name;
    std::string identity;
    int island_number;

    GraphNode();
};

class Graph {
private:
    std::vector<GraphNode> nodes;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> islands;

public:
    Graph(int numNodes, int numIslands, int islandID);
    void addNode();
    int dijkstraShortestPath(int source, int destination, std::vector<std::string>& path) const;  // Add const here
    int calculateShortestDistance(const std::vector<Graph>& islands, const std::string& src, const std::string& dest, std::vector<std::string>& path);
    void printGraph();
};

#endif
