////https://leetcode.com/problems/pascals-triangle/?envType=problem-list-v2&envId=array&difficulty=EASY
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle; // This will hold the rows of Pascal's triangle

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Initialize a row with all elements set to 1

            // Each triangle element (except the first and last one) is the sum of the two elements above it
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row); // Add the row to the triangle
        }
        
        return triangle; // Return the completed triangle
    }
    /*
    Definition of Binomial Coefficient:
    
    The binomial coefficient C(n, k) represents the number of ways to choose k elements
    from a set of n elements without regard to the order of selection. It is defined as:

    C(n, k) = n! / (k! * (n - k)!)

    Where n! (n factorial) is the product of all positive integers up to n.

    Example:
    --------
    Consider n = 5 and k = 2. We are calculating C(5, 2), which means we want to find
    how many ways we can choose 2 elements from a set of 5 elements.

    C(5, 2) = 5! / (2! * (5 - 2)!)
            = (5 * 4 * 3 * 2 * 1) / [(2 * 1) * (3 * 2 * 1)]
            = 120 / (2 * 6)
            = 120 / 12
            = 10

    Therefore, there are 10 ways to choose 2 elements from a set of 5 elements.
    
    Properties of Binomial Coefficient:
    - C(n, 0) = 1 for any n >= 0 (There is only one way to choose 0 elements)
    - C(n, n) = 1 for any n >= 0 (There is only one way to choose all n elements)
    - C(n, k) = C(n, n - k) (Choosing k elements is the same as leaving out (n-k) elements)
    - Recursively defined as:
        C(n, k) = C(n - 1, k - 1) + C(n - 1, k)

    Pascal's Triangle Example :
    
    Pascal's triangle is constructed by calculating the binomial coefficients for each element in the rows.
    Each row corresponds to values of C(n, k) for different k values, where n is the row number (starting from 0).

    Example:
    --------
    Input: numRows = 5
    Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

    Explanation:
    ------------
    - Row 0: 
    C(0, 0) = 1 --> [1]
    
    - Row 1: 
    C(1, 0) = 1, 
    C(1, 1) = 1 --> [1, 1]
    
    - Row 2: 
    C(2, 0) = 1, 
    C(2, 1) = 2, 
    C(2, 2) = 1 --> [1, 2, 1]
    
    - Row 3: 
    C(3, 0) = 1, 
    C(3, 1) = 3, 
    C(3, 2) = 3, 
    C(3, 3) = 1 --> [1, 3, 3, 1]
    
    - Row 4: 
    C(4, 0) = 1, 
    C(4, 1) = 4, 
    C(4, 2) = 6, 
    C(4, 3) = 4, 
    C(4, 4) = 1 --> [1, 4, 6, 4, 1]

    Breakdown:
    ----------
    1. Row 0 is just a single 1:                [1]
    
    2. Row 1 has two 1's:                       [1, 1]
    
    3. Row 2: Use binomial coefficients:
       C(2, 0) = 1, 
       C(2, 1) = 2, 
       C(2, 2) = 1  -> [1, 2, 1]
    
    4. Row 3: Use binomial coefficients:
       C(3, 0) = 1, 
       C(3, 1) = 3, 
       C(3, 2) = 3, 
       C(3, 3) = 1 -> [1, 3, 3, 1]
    
    5. Row 4: Use binomial coefficients:
       C(4, 0) = 1, 
       C(4, 1) = 4, 
       C(4, 2) = 6, 
       C(4, 3) = 4, 
       C(4, 4) = 1 -> [1, 4, 6, 4, 1]
       
    These steps continue for each additional row, always using the formula for binomial coefficients:
    C(n, k) = n! / (k! * (n - k)!)


[
 [1],
 [1, 1],
 [1, 2, 1],
 [1, 3, 3, 1],
 [1, 4, 6, 4, 1]
]

*/

};