#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Handle the case when the needle is an empty string
        if (needle.empty()) {
            return 0;
        }
        
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        
        // We only need to check up to the point where the remaining part of haystack
        // is at least as long as the needle
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            // Check if the substring of haystack starting at i matches the needle
            if (haystack.substr(i, needleLen) == needle) {
                return i;
            }
        }
        
        return -1;  // Return -1 if the needle is not found in the haystack
    }
};
