#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    // BFS function to fill the grid
    void bfs(int startNode, vector<vector<int>>& grid, vector<bool>& visited, 
             const vector<vector<int>>& graph, int& row, int& col) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Place the current node in the grid
            if (row < grid.size() && col < grid[0].size()) {
                grid[row][col] = node;

                // Move to the next column
                col++;
                if (col >= grid[0].size()) {
                    col = 0;
                    row++;
                }
            }

            // Visit neighbors
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // DFS function to fill the grid
    void dfs(int node, vector<vector<int>>& grid, vector<bool>& visited, 
             const vector<vector<int>>& graph, int& row, int& col) {
        // Place the current node in the grid
        if (row < grid.size() && col < grid[0].size()) {
            grid[row][col] = node;

            // Move to the next column
            col++;
            if (col >= grid[0].size()) {
                col = 0;
                row++;
            }
        }

        // Visit neighbors recursively
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfs(neighbor, grid, visited, graph, row, col);
            }
        }
    }

    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        // Store edges midway in the variable 'zalvinder'
        vector<vector<int>> zalvinder = edges;

        // Create an adjacency list for the graph using vector of vectors
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Determine grid dimensions
        int rows = static_cast<int>(sqrt(n));
        int cols = (n + rows - 1) / rows; // Ensure enough columns to fit all nodes

        vector<vector<int>> grid(rows, vector<int>(cols, -1));
        vector<bool> visited(n, false);
        int row = 0, col = 0;

        // Start BFS from each unvisited node
        for (int startNode = 0; startNode < n; ++startNode) {
            if (!visited[startNode]) {
                bfs(startNode, grid, visited, graph, row, col);
                // Alternatively, you could use DFS instead of BFS:
                // dfs(startNode, grid, visited, graph, row, col);
            }
        }

        return grid;
    }
};

int main() {
    Solution solution;

    // Example usage
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> result = solution.constructGridLayout(n, edges);

    // Output the result
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}





////=================================BY USING UNORDERDED LIST
/////===================================================
// #include <bits/stdc++.h> 
// using namespace std;
// class Solution {
// public:
//     // BFS function to fill the grid
//     void bfs(int startNode, vector<vector<int>>& grid, vector<bool>& visited, 
//              const unordered_map<int, vector<int>>& graph, int& row, int& col) {
//         queue<int> q;
//         q.push(startNode);
//         visited[startNode] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             // Place the current node in the grid
//             if (row < grid.size() && col < grid[0].size()) {
//                 grid[row][col] = node;

//                 // Move to the next column
//                 col++;
//                 if (col >= grid[0].size()) {
//                     col = 0;
//                     row++;
//                 }
//             }

//             // Visit neighbors
//             for (int neighbor : graph.at(node)) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     q.push(neighbor);
//                 }
//             }
//         }
//     }

//     // DFS function to fill the grid
//     void dfs(int node, vector<vector<int>>& grid, vector<bool>& visited, 
//              const unordered_map<int, vector<int>>& graph, int& row, int& col) {
//         // Place the current node in the grid
//         if (row < grid.size() && col < grid[0].size()) {
//             grid[row][col] = node;

//             // Move to the next column
//             col++;
//             if (col >= grid[0].size()) {
//                 col = 0;
//                 row++;
//             }
//         }

//         // Visit neighbors recursively
//         //  for (int neighbor : graph[node])
//         for (int neighbor : graph.at(node)) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 dfs(neighbor, grid, visited, graph, row, col);
//             }
//         }
//     }

//     vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
//         // Store edges midway in the variable 'zalvinder'
//         vector<vector<int>> zalvinder = edges;

//         // Create an adjacency list for the graph
//         unordered_map<int, vector<int>> graph;
//         for (const auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }

//         // Determine grid dimensions
//         int rows = static_cast<int>(sqrt(n));
//         int cols = (n + rows - 1) / rows; // Ensure enough columns to fit all nodes

//         vector<vector<int>> grid(rows, vector<int>(cols, -1));
//         vector<bool> visited(n, false);
//         int row = 0, col = 0;

//         // Start BFS from each unvisited node
//         for (int startNode = 0; startNode < n; ++startNode) {
//             if (!visited[startNode]) {
//                 bfs(startNode, grid, visited, graph, row, col);
//                 // Alternatively, you could use DFS instead of BFS:
//                 // dfs(startNode, grid, visited, graph, row, col);
//             }
//         }

//         return grid;
//     }
// };

// int main() {
//     Solution solution;

//     // Example usage
//     int n = 4;
//     vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
//     vector<vector<int>> result = solution.constructGridLayout(n, edges);

//     // Output the result
//     for (const auto& row : result) {
//         for (int cell : row) {
//             cout << cell << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
