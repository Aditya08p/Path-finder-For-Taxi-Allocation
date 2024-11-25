## **Path Finder for Taxi Allocation**

### **Introduction**
This project implements a taxi allocation system using advanced data structures like Tries and Graphs. It supports operations like shortest path calculation and dynamic graph modifications for efficient taxi route management.

---

### **Features**
1. **Dynamic Graph Representation:** Models road networks with adjacency matrices for efficient pathfinding.
2. **Efficient Search:** Implements Tries for location-based search and auto-complete functionality.
3. **Shortest Path Calculation:** Uses Dijkstra's algorithm for optimized routing.
4. **Interactive Menu:** Allows adding nodes, printing graphs, and finding shortest paths.

---

### **Folder Structure**
```
Path-Finder-Taxi-Allocation/
├── README.md            # Project overview and instructions
├── LICENSE              # Project license
├── .gitignore           # Files to exclude from version control
├── src/                 # Source code folder
│   ├── main.cpp         # Main program
│   ├── Trie.h           # Header file for Trie implementation
│   ├── Trie.cpp         # Implementation of Trie
│   ├── Graph.h          # Header file for Graph implementation
│   ├── Graph.cpp        # Implementation of Graph
└── docs/                # Documentation folder
```

---

### **Requirements**
- A C++ compiler (e.g., `g++`)
- Basic knowledge of compiling and running C++ programs

---

### **How to Run**
#### **Step 1: Compile the Program**
Navigate to the project folder in your terminal/command prompt and run:
```bash
g++ -o pathfinder src/main.cpp src/Trie.cpp src/Graph.cpp
```

#### **Step 2: Run the Executable**
After successful compilation, execute the program:
- **On Linux/Mac:**
  ```bash
  ./pathfinder
  ```
- **On Windows:**
  ```bash
  pathfinder.exe
  ```

---

### **Program Functionality**
1. **Print Graphs:** Displays the nodes, edges, and adjacency matrix of all islands.
2. **Add Nodes:** Dynamically adds a new node to an island graph and updates the adjacency matrix.
3. **Find Shortest Path:** Calculates the shortest path between two places using Dijkstra’s algorithm and displays the path.

---

### **Sample Run**
#### Input:
- Number of islands: `2`
- Island 1 nodes: `A`, `B` with distances `A->B = 10`
- Island 2 nodes: `C`, `D` with distances `C->D = 5`

#### Menu:
1. Print all graphs
2. Add a new node
3. Find shortest path between two places
4. Exit

#### Output:
```plaintext
Menu:
1. Print all graphs
2. Add a new node to a graph
3. Find shortest path between two places
4. Exit
Enter your choice: 3
Enter source: A
Enter destination: B
Shortest path: A -> B
Total distance: 10
```

---

### **Future Scope**
- Integration of real-time data for dynamic taxi allocation.
- Support for cross-island shortest path calculation.
- Implementation of machine learning models for demand prediction.

---

### **Contributing**
Contributions are welcome! Fork the repository, make changes, and create a pull request.

---

### **License**
This project is licensed under the MIT License.
