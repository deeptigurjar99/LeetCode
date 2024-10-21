#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer forward if it's not an alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Move right pointer backward if it's not an alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare the characters, convert both to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};
