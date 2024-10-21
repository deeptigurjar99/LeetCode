#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        
        // Iterate from the end of both strings
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0'; // Convert character to integer
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert character to integer
                j--;
            }
            
            // Append the current bit (sum % 2) to the result
            result = to_string(sum % 2) + result;
            
            // Update carry (sum / 2)
            carry = sum / 2;
        }
        
        return result;
    }
};
