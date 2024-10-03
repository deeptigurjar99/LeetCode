#include <unordered_map>
#include <vector>
#include <numeric>  // for accumulate

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Calculate the total sum of the array
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        // Get the remainder when totalSum is divided by p
        int remainder = totalSum % p;
        
        // If the remainder is already 0, the total sum is divisible by p
        if (remainder == 0) return 0;
        
        // Map to store prefix sum modulo p
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1; // To handle cases where removing from the start is required
        int currentMod = 0, minLen = nums.size();
        
        // Iterate over the array to find the minimal subarray
        for (int i = 0; i < nums.size(); ++i) {
            currentMod = (currentMod + nums[i]) % p;
            int targetMod = (currentMod - remainder + p) % p;
            
            // Check if the target modulo value exists in the prefix map
            if (prefixMod.find(targetMod) != prefixMod.end()) {
                minLen = min(minLen, i - prefixMod[targetMod]);
            }
            
            // Store the current prefix modulo in the map
            prefixMod[currentMod] = i;
        }
        
        // Return the minimum length if it's valid, otherwise return -1
        return minLen == nums.size() ? -1 : minLen;
    }
};
