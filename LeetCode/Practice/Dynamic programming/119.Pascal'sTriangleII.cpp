
///  https://leetcode.com/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY/
class Solution {
public:
    // vector<int> getRow(int rowIndex) {
    //     vector<int> row(rowIndex + 1, 0);  // Initialize a row with rowIndex + 1 elements
    //     row[0] = 1;  // The first element is always 1

    //     // Build the row iteratively
    //     for (int i = 1; i <= rowIndex; i++) {
    //         // Update the row in reverse order to avoid overwriting the values
    //         for (int j = i; j > 0; j--) {
    //             row[j] = row[j] + row[j - 1];
    //         }
    //     }

    //     return row;
    // }


     // Define the memoization table
    vector<vector<int>> memo;

    vector<int> getRow(int rowIndex) {
        // Initialize the memo table with -1 to indicate uncomputed values
        memo.resize(rowIndex + 1, vector<int>(rowIndex + 1, -1));
        
        vector<int> row;
        for (int i = 0; i <= rowIndex; i++) {
            int positionValue = computePascal(rowIndex, i);
            row.push_back(positionValue);
        }
        return row;
    }

    // Recursive function with memoization to calculate Pascal's triangle values
    int computePascal(int i, int j) {
        // Base cases: first and last element of the row is 1
        if (j == 0 || j == i) {
            return 1;
        }

        // Check if the value is already computed and stored in memo
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Compute the value recursively and store it in the memo table
        memo[i][j] = computePascal(i - 1, j - 1) + computePascal(i - 1, j);
        return memo[i][j];
    }
};