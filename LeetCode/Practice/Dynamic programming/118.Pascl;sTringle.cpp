////https://leetcode.com/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY

class Solution {
public:
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> triangle; // This will hold the rows of Pascal's triangle

    //     for (int i = 0; i < numRows; i++) {
    //         vector<int> row(i + 1, 1); // Initialize a row with all elements set to 1

    //         // Each triangle element (except the first and last one) is the sum of the two elements above it
    //         for (int j = 1; j < i; j++) {
    //             row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    //         }

    //         triangle.push_back(row); // Add the row to the triangle
    //     }
        
    //     return triangle; // Return the completed triangle
    // }



    ////Using recursion
    vector<vector<int>> memo;  // Memoization table to store previously computed values
    
    // Recursive function to generate the element at row i and column j
    int generateElement(int i, int j) {
        // Base case: the first or last element of a row is always 1
        if (j == 0 || j == i) {
            return 1;
        }
        
        // Check if the value is already computed in the memo table
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // Recursively compute the value using the Pascal's triangle property
        memo[i][j] = generateElement(i - 1, j - 1) + generateElement(i - 1, j);
        
        return memo[i][j];
    }
    
    vector<vector<int>> generate(int numRows) {
        // Initialize memoization table with -1
        memo.resize(numRows, vector<int>(numRows, -1));
        
        vector<vector<int>> triangle(numRows);  // This will hold the rows of Pascal's triangle
        
        // Build each row using the recursive function
        for (int i = 0; i < numRows; i++) {
            triangle[i].resize(i + 1);  // Resize the row to have 'i+1' elements
            for (int j = 0; j <= i; j++) {
                // Populate each element using the recursive function
                triangle[i][j] = generateElement(i, j);
            }
        }
        
        return triangle;  // Return the completed triangle
    }
    
};