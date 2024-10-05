#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Map(26, 0), s2Map(26, 0);
        
        // Fill frequency map for s1 and the first window in s2
        for (int i = 0; i < s1.length(); i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        // Sliding window over s2
        for (int i = s1.length(); i < s2.length(); i++) {
            if (s1Map == s2Map) {
                return true;
            }

            // Slide the window
            s2Map[s2[i] - 'a']++; // Include the next character
            s2Map[s2[i - s1.length()] - 'a']--; // Exclude the previous character
        }

        // Check the last window
        return s1Map == s2Map;
    }
};
