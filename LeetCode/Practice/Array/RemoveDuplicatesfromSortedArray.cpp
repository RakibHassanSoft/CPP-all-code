/////https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array&difficulty=EASY
class Solution {
public:
    // int removeDuplicates(std::vector<int>& nums) {
    //    set<int> uniqueSet;  // To store unique elements

    //     // Fill the set with unique elements
    //     for (int num : nums) {
    //         uniqueSet.insert(num);
    //     }

    //     // Copy unique elements back to the original array
    //     int index = 0;
    //     for (int uniqueNum : uniqueSet) {
    //         nums[index++] = uniqueNum;  // Modify nums in place
    //     }

    //     // Return the number of unique elements
    //     return uniqueSet.size(); // Number of unique elements
    // }


    ////Two pointers  O(nlogn)
    //  int removeDuplicates(std::vector<int>& nums) {
    //     if (nums.empty()) return 0; // Handle edge case for empty array
        
    //     int j = 0; // Pointer for the last unique element

    //     for (int i = 1; i < nums.size(); i++) {
    //         // If we find a new unique element
    //         if (nums[i] != nums[j]) {
    //             j++; // Move the pointer for unique elements
    //             nums[j] = nums[i]; // Update the position with the new unique element
    //         }
    //     }

    //     // Return the number of unique elements
    //     return j + 1; // j is index, so +1 gives the count of unique elements
    // }

   //// hash map
    int removeDuplicates(std::vector<int>& nums) {
       unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++; // Count occurrences
        }

       vector<int> uniqueElements; // To store unique elements
        for (const auto& entry : countMap) {
            uniqueElements.push_back(entry.first); // Store unique elements
        }

        // Sort the unique elements
       sort(uniqueElements.begin(), uniqueElements.end());

        // Place the sorted unique elements back into nums
        for (int i = 0; i < uniqueElements.size(); i++) {
            nums[i] = uniqueElements[i];
        }

        return uniqueElements.size(); // Return the number of unique elements
    }
};