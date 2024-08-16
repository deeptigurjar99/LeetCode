#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        for (int i = 1; i < arrays.size(); i++) {
            // Calculate the distance using current array's min and max values with previous min and max
            maxDist = max(maxDist, abs(arrays[i].back() - minVal));
            maxDist = max(maxDist, abs(maxVal - arrays[i][0]));
            
            // Update the global min and max values
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }
        
        return maxDist;
    }
};
