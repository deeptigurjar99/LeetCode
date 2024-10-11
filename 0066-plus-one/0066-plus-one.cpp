#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the digits array from the end
        for (int i = n - 1; i >= 0; i--) {
            // If the digit is less than 9, just increment it and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // Otherwise, set the current digit to 0
            digits[i] = 0;
        }
        
        // If we have reached here, it means all digits were 9
        // We need to add an additional digit 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
