//// https://leetcode.com/problems/climbing-stairs/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY

class Solution {
public:
    // int climbStairs(int n) {
    //     vector<int> dp(n + 1, -1);  // Create a memoization array initialized with -1
        
    //     // Base cases
    //     if (n == 0 || n == 1) return 1;

    //     dp[0] = 1;
    //     dp[1] = 1;
        
    //     // Fill the memoization array using the recurrence relation
    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
        
    //     return dp[n];  // The result for n stairs
    // }
////Clear code

       vector<int> memo;  // Vector to store already computed results
    
    int climbStairs(int n) {
        // Initialize the memo array with size n+1 and set all values to -1 (uncomputed)
        memo.resize(n + 1, -1);
        
        // Call the recursive helper function to compute the result
        return climb(n);
    }
    
    int climb(int n) {
        // Base cases: If n is 0 or 1, there is only one way to climb
        if (n == 0 || n == 1) {
            return 1;
        }
        
        // If the result for this 'n' is already computed, return the cached result
        if (memo[n] != -1) {
            return memo[n];
        }
        
        // Otherwise, compute the result recursively and store it in memo
        memo[n] = climb(n - 1) + climb(n - 2);
        
        // Return the computed result for 'n'
        return memo[n];
    }



    
    // int climbStairs(int n) {
    //     // Base cases
    //     if (n == 0 || n == 1) return 1;

    //     int prev1 = 1; // For n = 1
    //     int prev2 = 1; // For n = 0
    //     int current;
        
    //     for (int i = 2; i <= n; i++) {
    //         current = prev1 + prev2;
    //         prev2 = prev1;
    //         prev1 = current;
    //     }
        
    //     return prev1;  // This stores the result for n stairs
    // }
    
    //Limite problem
    // int climbStairs(int n) {
    //     // Base cases: If there are 0 or 1 steps, there's only one way to climb them
    //     if (n == 0 || n == 1) {
    //         return 1;
    //     }
        
    //     // Recursive case: Sum of ways to reach (n-1) and (n-2)
    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }



    
};
