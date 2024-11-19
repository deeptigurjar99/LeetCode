class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        // Use two variables to store the last two steps
        int prev1 = 1, prev2 = 2;
        
        // Start calculating from step 3 to n
        for (int i = 3; i <= n; ++i) {
            int current = prev1 + prev2; // Number of ways to reach the current step
            prev1 = prev2;  // Update prev1 to be the previous step
            prev2 = current; // Update prev2 to be the current step
        }
        
        // The answer will be in prev2 (which corresponds to step n)
        return prev2;
    }
};
