#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Create an unordered set
    unordered_set<int> nodes; // O(1) for allocation

    // Adding elements (nodes)
    nodes.insert(0); // O(1) average for insert
    nodes.insert(1); // O(1) average for insert
    nodes.insert(2); // O(1) average for insert
    nodes.insert(3); // O(1) average for insert
    nodes.insert(2); // Duplicate element (won't be added)

    // Output the elements in the set
    cout << "Nodes in the set: ";
    for (int node : nodes) { // O(n) where n is the number of unique nodes
        cout << node << " "; // Output each node
    }
    cout << endl;

    // Example usage of built-in functions
    cout << "Size of set: " << nodes.size() << endl; // O(1) for size
    cout << "Is the set empty? " << (nodes.empty() ? "Yes" : "No") << endl; // O(1) for empty check

    // Checking if a value exists
    int checkNode = 2;
    cout << "Does node " << checkNode << " exist? " << (nodes.count(checkNode) ? "Yes" : "No") << endl; // O(1) for count

    // Removing an element
    nodes.erase(1); // O(1) average for erase
    cout << "After removing node 1, size of set: " << nodes.size() << endl; // O(1) for size

    // Trying to remove a non-existing element
    nodes.erase(4); // O(1) average for erase (no effect if not found)

    // Output the elements in the set after removal
    cout << "Nodes in the set after removal: ";
    for (int node : nodes) { // O(n)
        cout << node << " "; // Output each node
    }
    cout << endl;

    return 0;
}
