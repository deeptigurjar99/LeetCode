class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        
        // Binary search on the distance
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            int left = 0;
            
            // Sliding window to count pairs with distance <= mid
            for (int right = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }
            
            // Check if we found at least k pairs with distance <= mid
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
