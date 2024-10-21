#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Adjust columnNumber to handle 1-based indexing
            columnNumber--;
            // Find the character corresponding to the current digit
            char c = 'A' + (columnNumber % 26);
            // Append the character to the result string
            result = c + result;
            // Move to the next digit in base 26
            columnNumber /= 26;
        }
        
        return result;
    }
};
