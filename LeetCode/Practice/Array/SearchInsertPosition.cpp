////https://leetcode.com/problems/search-insert-position/?envType=problem-list-v2&envId=array&difficulty=EASY
class Solution {
public:
////Binary search(logn)
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid potential overflow

            if (nums[mid] == target) {
                return mid; // Target found
            }
            else if (nums[mid] < target) {
                left = mid + 1; // Move to the right half
            }
            else {
                right = mid - 1; // Move to the left half
            }
        }

        // If not found, 'left' is the index where the target should be inserted
        return left;
    }

////Liner seach  O(N)
// int searchInsert(std::vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] >= target) {
//                 return i; // Return index if target is found or the first greater element
//             }
//         }
//         return nums.size(); // If target is greater than all elements, return size
//     }

////Lower Bound
// int searchInsert(vector<int>& nums, int target) {
//         auto it = lower_bound(nums.begin(), nums.end(), target);
//         return it - nums.begin(); // Calculate the index from the iterator
//     }
};