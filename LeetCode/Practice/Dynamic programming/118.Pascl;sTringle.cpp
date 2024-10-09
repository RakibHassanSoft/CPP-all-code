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


/*
Binomial Coefficients Rules and Properties:

1. **Definition of Binomial Coefficients**:
   The binomial coefficient is defined as:
   C(n, k) = n! / (k!(n - k)!)

   Where:
   - n is the total number of items.
   - k is the number of items chosen.
   - ! represents the factorial of a number.

2. **Symmetry Rule**:
   Binomial coefficients are symmetric:
   C(n, k) = C(n, n - k)
   Example: C(5, 2) = C(5, 3) = 10

3. **Pascal's Rule** (Recursive Rule):
   The binomial coefficient follows a recursive relationship:
   C(n, k) = C(n-1, k-1) + C(n-1, k)
   Example: C(5, 2) = C(4, 1) + C(4, 2) = 4 + 6 = 10

4. **Boundary Conditions**:
   - C(n, 0) = C(n, n) = 1, for all n ≥ 0.
   - Choosing 0 or all n items always results in 1 way.

5. **Summation Rule**:
   The sum of all binomial coefficients for a given n is equal to 2^n:
   ∑(k=0 to n) C(n, k) = 2^n
   Example: For n = 3: 1 + 3 + 3 + 1 = 8 = 2^3

6. **Binomial Theorem**:
   The binomial coefficients appear in the expansion of a binomial expression:
   (x + y)^n = ∑(k=0 to n) C(n, k) x^(n-k) y^k
   Example: (x + y)^3 = x^3 + 3x^2y + 3xy^2 + y^3

7. **Vandermonde's Identity**:
   A more advanced identity involving binomial coefficients:
   C(m + n, r) = ∑(k=0 to r) C(m, k) C(n, r-k)

8. **Multiplication Rule**:
   If k ≤ n, then multiplying binomial coefficients gives:
   k * C(n, k) = (n - k + 1) * C(n, k-1)

9. **Negative Binomial Coefficients**:
   For negative integers n, binomial coefficients are defined using:
   C(n, k) = n(n - 1)(n - 2) ... (n - k + 1) / k!

10. **Lucas' Theorem**:
    Lucas' Theorem calculates binomial coefficients modulo a prime number:
    C(n, k) ≡ C(n mod p, k mod p) (mod p)

These rules and properties make binomial coefficients a powerful tool in combinatorics, probability theory, and algebra.
*/
