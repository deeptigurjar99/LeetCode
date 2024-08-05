#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Step 2: Find the element just larger than nums[i] to swap with
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap elements at i and j
            std::swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the suffix starting from i + 1
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
