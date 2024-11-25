#include "Trie.h"
#include "Graph.h"

int main() {
    Trie trie;
    int numIslands;
    std::cout << "Enter number of islands: ";
    std::cin >> numIslands;

    std::vector<Graph> islands;
    for (int i = 0; i < numIslands; i++) {
        int numNodes;
        std::cout << "Enter number of nodes in Island " << i + 1 << ": ";
        std::cin >> numNodes;
        islands.emplace_back(numNodes, numIslands, i + 1);
    }

    // Menu implementation here
    return 0;
}
