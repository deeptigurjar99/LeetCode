#include <vector>
#include <numeric> 
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int totalRolls = n + m;

        
        int targetSum = mean * totalRolls;

        
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);

        
        int missingSum = targetSum - currentSum;

        
        if (missingSum < n || missingSum > 6 * n) {
            return {}; 
        }

        
        vector<int> result(n, missingSum / n); 

       
        int remainder = missingSum % n;

        for (int i = 0; i < remainder; ++i) {
            result[i]++;
        }

        return result;
    }
};
