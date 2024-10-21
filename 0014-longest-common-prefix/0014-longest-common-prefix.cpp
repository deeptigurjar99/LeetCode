#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Return empty string if no strings are provided

        // Initialize the prefix as the first string
        string prefix = strs[0];
        
        // Compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            // Find the common prefix between the current prefix and the next string
            while (strs[i].find(prefix) != 0) {
                // Shrink the prefix if it doesn't match
                prefix = prefix.substr(0, prefix.size() - 1);
                
                // If the prefix becomes empty, return an empty string
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
