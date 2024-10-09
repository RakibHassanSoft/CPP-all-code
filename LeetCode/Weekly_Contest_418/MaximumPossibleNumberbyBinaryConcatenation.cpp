#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    // Function to convert an integer to its binary representation
    string toBinary(int num) {
        if (num == 0) return "0";
        
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }

    // Function to concatenate the binary representations of an array of integers
    string concatenateBinaries(const vector<int>& nums) {
        string concatenatedBinary = "";
        for (int num : nums) {
            concatenatedBinary += toBinary(num);
        }
        return concatenatedBinary;
    }

    // Function to convert a binary string to its decimal representation
    int binaryToDecimal(const string& binary) {
        int decimalValue = 0;
        int base = 1; // Initialize base (2^0)
        for (int i = binary.size() - 1; i >= 0; --i) {
            if (binary[i] == '1') {
                decimalValue += base;
            }
            base *= 2;
        }
        return decimalValue;
    }

    // Function to swap two elements in the array
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Function to generate all permutations and find the maximum decimal value from concatenated binaries
    void generatePermutations(vector<int>& nums, int start, int& maxDecimalValue) {
        if (start == nums.size()) {
            string concatenatedBinary = concatenateBinaries(nums);
            int decimalValue = binaryToDecimal(concatenatedBinary);
            if (decimalValue > maxDecimalValue) 
                maxDecimalValue = decimalValue;
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums, start, i); // Swap the current index with the start
            generatePermutations(nums, start + 1, maxDecimalValue); // Recursively call to generate further permutations
            swap(nums, start, i); // Backtrack to restore the original array
        }
    }

    // Main function to find the maximum good number
    int maxGoodNumber(vector<int>& nums) {
        int maxDecimalValue = 0; 
        generatePermutations(nums, 0, maxDecimalValue); 
        return maxDecimalValue; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input //30
    // vector<int> nums = {2, 8, 16}; // Example input // 1296
    int maxGoodValue = solution.maxGoodNumber(nums);
    cout << "Maximum Good Number: " << maxGoodValue << endl; // Output the result
    return 0;
}
