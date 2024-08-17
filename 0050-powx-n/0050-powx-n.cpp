class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the edge case when n is INT_MIN
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1;
        while (N) {
            if (N % 2) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        return result;
    }
};
