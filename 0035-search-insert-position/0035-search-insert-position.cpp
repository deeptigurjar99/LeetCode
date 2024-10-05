#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // To avoid potential overflow

            if (nums[mid] == target) {
                return mid; // Target found, return its index
            }
            else if (nums[mid] < target) {
                left = mid + 1; // Target is in the right half
            }
            else {
                right = mid - 1; // Target is in the left half
            }
        }

        // If the target is not found, 'left' will be the index where it should be inserted
        return left;
    }
};
