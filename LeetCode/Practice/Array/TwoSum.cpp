#include <bits/stdc++.h> 
using namespace std;
///// brute-force approach
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> V;
//         for( int i = 0;i < nums.size()-1;i++){
//             for( int j = i+1 ;j < nums.size();j++){
//                   if( nums[i]+nums[j] == target){
//                     V.push_back(i);
//                     V.push_back(j);
//                     break;
//                   }
//             }
//         }

//         return V;

//     }
// };

//// NUmbere 2    Hash Map Approach
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> map;  // to store number and its index
        
//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];
            
//             // Check if the complement is already in the map
//             if (map.find(complement) != map.end()) {
//                 return {map[complement], i};  // return indices of complement and current number
//             }
            
//             // If complement is not found, store the current number with its index
//             map[nums[i]] = i;
//         }
        
//         // If no solution is found, return an empty vector (this case should not happen as per the problem statement)
//         return {};
//     }
// };


////Number 3    two-pointer technique 
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         // Create a copy of the original array to keep track of original indices
//         vector<pair<int, int>> num_with_index;
//         for (int i = 0; i < nums.size(); i++) {
//             num_with_index.push_back({nums[i], i});
//         }
        
//         // Sort the array based on values
//         sort(num_with_index.begin(), num_with_index.end());
        
//         int left = 0, right = nums.size() - 1;
        
//         while (left < right) {
//             int sum = num_with_index[left].first + num_with_index[right].first;
            
//             if (sum == target) {
//                 // Return original indices
//                 return {num_with_index[left].second, num_with_index[right].second};
//             } else if (sum < target) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }
        
//         return {};  // In case no solution is found
//     }
// };

//// Number 4 with O(nlogn)    Binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_with_index;
        
        // Store the numbers along with their original indices
        for (int i = 0; i < nums.size(); i++) {
            num_with_index.push_back({nums[i], i});
        }
        
        // Sort the array based on the values of the numbers
        sort(num_with_index.begin(), num_with_index.end());
        
        // Iterate through the sorted array
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - num_with_index[i].first;
            
            // Use binary search to find the complement
            int left = i + 1;
            int right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (num_with_index[mid].first == complement) {
                    return {num_with_index[i].second, num_with_index[mid].second}; // Return original indices
                } else if (num_with_index[mid].first < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return {}; // Return an empty vector if no solution is found
    }
};


