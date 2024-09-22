class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // Decrement k because we start from 1 as the first lexicographical number
        
        while (k > 0) {
            long long step = calculateSteps(curr, n);  // Calculate steps between curr and curr + 1
            if (step <= k) {
                // If the steps are less than or equal to k, we move to the next prefix
                curr++;
                k -= step;
            } else {
                // Otherwise, we go deeper in the current prefix
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
    
    // Helper function to calculate the number of steps between `curr` and `curr + 1`
    long long calculateSteps(long long curr, long long n) {
        long long steps = 0;
        long long first = curr, last = curr;
        
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return steps;
    }
};
