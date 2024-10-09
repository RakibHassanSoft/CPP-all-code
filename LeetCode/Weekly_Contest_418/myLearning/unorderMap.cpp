#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Create an adjacency list using unordered_map
    unordered_map<int, vector<int>> graph;

    // Adding edges to the graph
    // Let's say we want to add edges: (0, 1), (0, 2), (1, 3)

    // Edge between 0 and 1
    graph[0].emplace_back(1); // O(1) average for push_back (amortized)
    graph[1].emplace_back(0); // O(1) average for push_back (amortized)

    // Edge between 0 and 2
    graph[0].insert(graph[0].begin(), 2); // O(n) because we may need to shift elements
    graph[2].emplace_back(0); // O(1) average for push_back (amortized)

    // Edge between 1 and 3
    graph[1].push_back(3); // O(1) average for push_back (amortized)
    graph[3].emplace_back(1); // O(1) average for push_back (amortized)

    // Output the adjacency list
    cout << "Adjacency List Representation of the Graph:\n";
    for (const auto& pair : graph) {
        cout << "Node " << pair.first << ": "; // Print the node number
        for (int neighbor : pair.second) { // Iterate through neighbors
            cout << neighbor << " "; // Print each neighbor
        }
        cout << endl; // New line after printing neighbors of a node
    }

    // Example usage of size and empty
    cout << "Number of neighbors for node 1: " << graph.at(1).size() << endl; // O(1) for size
    cout << "Is the neighbor list for node 2 empty? " << (graph.at(2).empty() ? "Yes" : "No") << endl; // O(1) for empty check

    // Clear the adjacency list for node 0
    graph.at(0).clear(); // O(n) since we need to deallocate all elements
    cout << "After clearing, number of neighbors for node 0: " << graph.at(0).size() << endl; // O(1) for size

    return 0;
}
