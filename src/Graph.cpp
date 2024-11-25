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

    std::cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            std::cin >> adj_list[i][j];
        }
    }
    std::cout << "Enter inter-island travel costs:\n";
    for (int i = 0; i < numIslands; i++) {
        std::cout << "Cost from Island " << islandID << " to Island " << i + 1 << ": ";
        std::cin >> islands[i];
    }
}

// Add a new node to the graph
void Graph::addNode() {
    GraphNode newNode;
    std::cout << "Enter name: ";
    std::cin >> newNode.name;
    std::cout << "Enter identity: ";
    std::cin >> newNode.identity;
    newNode.island_number = nodes[0].island_number;

    nodes.push_back(newNode);

    // Resize adjacency matrix
    int newSize = adj_list.size() + 1;
    adj_list.resize(newSize, std::vector<int>(newSize, -1));

    // Input distances for the new node
    for (int i = 0; i < newSize; i++) {
        std::cout << "Enter distance from " << nodes[i].name << ": ";
        std::cin >> adj_list[newSize - 1][i];
        adj_list[i][newSize - 1] = adj_list[newSize - 1][i];
    }
}

// Dijkstra's Algorithm for shortest path
int Graph::dijkstraShortestPath(int source, int destination, std::vector<std::string>& path) const {  // Add const here
    int n = adj_list.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    dist[source] = 0;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (adj_list[u][v] != -1 && dist[u] + adj_list[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_list[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Reconstruct the path
    for (int at = destination; at != -1; at = parent[at]) {
        path.insert(path.begin(), nodes[at].name);
    }

    return dist[destination];
}

// Calculate shortest distance between places
int Graph::calculateShortestDistance(const std::vector<Graph>& islands, const std::string& src, const std::string& dest, std::vector<std::string>& path) {
    int srcIsland = -1, destIsland = -1, srcNode = -1, destNode = -1;

    // Identify source and destination nodes
    for (size_t i = 0; i < islands.size(); i++) {
        for (size_t j = 0; j < islands[i].nodes.size(); j++) {
            if (islands[i].nodes[j].name == src) {
                srcIsland = i;
                srcNode = j;
            }
            if (islands[i].nodes[j].name == dest) {
                destIsland = i;
                destNode = j;
            }
        }
    }

    if (srcIsland == destIsland) {
        return islands[srcIsland].dijkstraShortestPath(srcNode, destNode, path);
    } else {
        std::cout << "Cross-island travel currently not supported in this demo.\n";
        return -1;
    }
}

// Print the graph
void Graph::printGraph() {
    std::cout << "Nodes in this graph:\n";
    for (const auto& node : nodes) {
        std::cout << node.name << " (" << node.identity << ") - Island " << node.island_number << "\n";
    }

    std::cout << "Adjacency Matrix:\n";
    for (const auto& row : adj_list) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
