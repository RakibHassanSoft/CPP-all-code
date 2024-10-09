////https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY
class Solution {
public:
//    vector<int> countBits(int n) {
//        vector<int> ans(n + 1, 0); // Initialize vector of size n + 1
        
//         for (int i = 1; i <= n; i++) {
//             // Count the number of 1's using previously computed values
//             ans[i] = ans[i >> 1] + (i & 1); // ans[i >> 1] is count of 1's in i // 2
//         }
        
//         return ans; // Return the result
//     }


// Memoization array   works same
    vector<int> memo;

    // Recursive function to count number of 1's in binary representation of i
    int countOnes(int i) {
        // Base case
        if (i == 0) return 0;
        
        // If already calculated, return the value from memo
        if (memo[i] != -1) return memo[i];

        // Calculate number of 1's recursively
        memo[i] = countOnes(i >> 1) + (i & 1);
        return memo[i];
    }

    vector<int> countBits(int n) {
        // Initialize memoization array with -1
        memo.resize(n + 1, -1);
        
        // Result vector to store counts for 0 to n
        vector<int> ans(n + 1);
        
        // Fill the result array using the recursive function
        for (int i = 0; i <= n; i++) {
            ans[i] = countOnes(i);
        }
        
        return ans; // Return the result
    }
};