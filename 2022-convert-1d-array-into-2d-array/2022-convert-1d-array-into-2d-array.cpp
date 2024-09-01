#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        // Check if it's possible to form the m x n 2D array
        if (m * n != original.size()) {
            return {}; // Return an empty 2D array if not possible
        }
        
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i];
        }
        
        return result;
    }
};
