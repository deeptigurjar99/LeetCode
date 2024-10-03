#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, return 0
        if (nums.empty()) return 0;

        // Index to place the next unique element
        int k = 1;

        // Loop through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is not equal to the previous one,
            // it's a new unique element
            if (nums[i] != nums[i - 1]) {
                // Move the unique element to the front
                nums[k] = nums[i];
                ++k; // Increase the count of unique elements
            }
        }

        // Return the number of unique elements
        return k;
    }
};
