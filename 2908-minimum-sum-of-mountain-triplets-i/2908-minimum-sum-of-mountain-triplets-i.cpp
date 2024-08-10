#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        bool foundMountain = false;

        for (int j = 1; j < n - 1; j++) {
            int leftMin = INT_MAX;
            int rightMin = INT_MAX;

            // Find the smallest number to the left of j where nums[i] < nums[j]
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    leftMin = min(leftMin, nums[i]);
                }
            }

            // Find the smallest number to the right of j where nums[k] < nums[j]
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j]) {
                    rightMin = min(rightMin, nums[k]);
                }
            }

            // If both leftMin and rightMin are valid, compute the sum
            if (leftMin != INT_MAX && rightMin != INT_MAX) {
                foundMountain = true;
                minSum = min(minSum, nums[j] + leftMin + rightMin);
            }
        }

        return foundMountain ? minSum : -1;
    }
};
