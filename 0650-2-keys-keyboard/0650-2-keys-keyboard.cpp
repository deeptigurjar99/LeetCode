class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0; // Special case: 1 character needs 0 operations
        
        int steps = 0;
        // Start checking from 2 to n to find factors
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) { // If i is a factor of n
                steps += i;     // Add the factor to steps
                n /= i;         // Reduce n
            }
        }
        return steps;
    }
};
