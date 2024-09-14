#include <vector>
#include <algorithm>  // for std::max
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());  // Find the maximum element
        int longest = 0, currentLength = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLength++;  // Increment current length of subarray with max value
                longest = max(longest, currentLength);  // Update the longest subarray
            } else {
                currentLength = 0;  // Reset the length if the current number is not max
            }
        }
        
        return longest;  // Return the length of the longest subarray
    }
};
