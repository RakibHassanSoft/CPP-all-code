#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Number of nodes
    int n = 4;
    
    // Create an adjacency list using vector
    vector<vector<int>> graph(n); // O(n) for allocating the vector (for n nodes)

    // Add edges
    graph[0].push_back(1); // O(1) average for push_back (amortized)
    graph[0].push_back(2); // O(1) average for push_back (amortized)
    graph[1].push_back(3); // O(1) average for push_back (amortized)
    graph[2].push_back(3); // O(1) average for push_back (amortized)
    
    // Since it's undirected, we need to add the reverse edges as well
    graph[1].push_back(0); // O(1) average for push_back (amortized)
    graph[2].push_back(0); // O(1) average for push_back (amortized)
    graph[3].push_back(1); // O(1) average for push_back (amortized)
    graph[3].push_back(2); // O(1) average for push_back (amortized)

    // Output the adjacency list
    for (int i = 0; i < n; i++) { // O(n) to iterate through nodes
        cout << "Node " << i << ": "; // Output node number
        for (int neighbor : graph[i]) { // O(k) where k is the number of neighbors
            cout << neighbor << " "; // Output each neighbor
        }
        cout << endl; // New line after printing neighbors of a node
    }

    // Example usage of built-in functions
    cout << "Number of neighbors for node 1: " << graph[1].size() << endl; // O(1) for size
    cout << "Is the neighbor list for node 2 empty? " << (graph[2].empty() ? "Yes" : "No") << endl; // O(1) for empty check

    // Clear the adjacency list for node 0
    graph[0].clear(); // O(n) since we need to deallocate all elements
    cout << "After clearing, number of neighbors for node 0: " << graph[0].size() << endl; // O(1) for size

    // Using iterator functions
    cout << "Using iterators to print neighbors of node 3:" << endl;
    cout << "Forward Iteration: ";
    for (auto it = graph[3].begin(); it != graph[3].end(); ++it) { // O(k) where k is the number of neighbors
        cout << *it << " "; // Dereference iterator to get neighbor
    }
    cout << endl;

    cout << "Reverse Iteration: ";
    for (auto rit = graph[3].rbegin(); rit != graph[3].rend(); ++rit) { // O(k) where k is the number of neighbors
        cout << *rit << " "; // Dereference reverse iterator to get neighbor
    }
    cout << endl;

    // Using constant iterators
    cout << "Using constant iterators for node 2:" << endl;
    cout << "Constant Forward Iteration: ";
    for (auto it = graph[2].cbegin(); it != graph[2].cend(); ++it) { // O(k) where k is the number of neighbors
        cout << *it << " "; // Dereference constant iterator to get neighbor
    }
    cout << endl;

    cout << "Constant Reverse Iteration: ";
    for (auto rit = graph[2].crbegin(); rit != graph[2].crend(); ++rit) { // O(k) where k is the number of neighbors
        cout << *rit << " "; // Dereference constant reverse iterator to get neighbor
    }
    cout << endl;

    return 0;
}
