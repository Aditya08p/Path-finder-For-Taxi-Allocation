#include "Trie.h"
#include "Graph.h"

int main() {
    Trie trie;
    std::vector<Graph> islands;

    std::cout << "Enter the number of islands: ";
    int numIslands;
    std::cin >> numIslands;

    for (int i = 0; i < numIslands; ++i) {
        std::cout << "Enter the number of nodes in Island " << i + 1 << ": ";
        int numNodes;
        std::cin >> numNodes;
        islands.emplace_back(numNodes, numIslands, i + 1);
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print all graphs\n";
        std::cout << "2. Add a new node to a graph\n";
        std::cout << "3. Find shortest path between two places\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            for (size_t i = 0; i < islands.size(); i++) {
                std::cout << "Island " << i + 1 << ":\n";
                islands[i].printGraph();
            }
            break;
        }
        case 2: {
            int islandIndex;
            std::cout << "Enter the island number to add a node: ";
            std::cin >> islandIndex;
            islands[islandIndex - 1].addNode();
            break;
        }
        case 3: {
            std::string src, dest;
            std::cout << "Enter source: ";
            std::cin >> src;
            std::cout << "Enter destination: ";
            std::cin >> dest;

            std::vector<std::string> path;
            int distance = islands[0].calculateShortestDistance(islands, src, dest, path);
            if (distance != -1) {
                std::cout << "Shortest path: ";
                for (size_t i = 0; i < path.size(); i++) {
                    std::cout << path[i];
                    if (i < path.size() - 1) std::cout << " -> ";
                }
                std::cout << "\nTotal distance: " << distance << "\n";
            }
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
