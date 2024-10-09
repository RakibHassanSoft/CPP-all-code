////https://leetcode.com/problems/fibonacci-number/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY

class Solution {
public:

    int fib(int n) {
        // Handle base cases
        if (n == 0) return 0; // F(0) = 0
        if (n == 1) return 1; // F(1) = 1
        
        // Create an array to store Fibonacci values
        vector<int> dp(n + 1);
        
        // Initialize the first two Fibonacci numbers
        dp[0] = 0; // F(0)
        dp[1] = 1; // F(1)
        
        // Fill the dp array using the Fibonacci formula
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2]; // F(n) = F(n-1) + F(n-2)
        }
        
        return dp[n]; // Return the nth Fibonacci number
    }



// Memoization array to store Fibonacci values
    // vector<int> memo;

    // Solution() {
    //     // Initialize the memoization array with -1
    //     memo.resize(1000, -1); // Change size according to your needs
    // }

    // int fib(int n) {
    //     // Base cases
    //     if (n == 0) return 0; // F(0) = 0
    //     if (n == 1) return 1; // F(1) = 1

    //     // Check if the value is already computed
    //     if (memo[n] != -1) {
    //         return memo[n]; // Return the cached result
    //     }

    //     // Compute and store the result in the memoization array
    //     memo[n] = fib(n - 1) + fib(n - 2);
    //     return memo[n]; // Return the computed Fibonacci number
    // }
};