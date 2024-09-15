#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> seen;
        seen[0] = -1;  // Base case, for when the entire string up to a point has even vowels
        int mask = 0, max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            // Update the mask for the current character if it is a vowel
            if (s[i] == 'a') mask ^= 1 << 0;
            else if (s[i] == 'e') mask ^= 1 << 1;
            else if (s[i] == 'i') mask ^= 1 << 2;
            else if (s[i] == 'o') mask ^= 1 << 3;
            else if (s[i] == 'u') mask ^= 1 << 4;

            // If this mask has been seen before, calculate the length of the substring
            if (seen.count(mask)) {
                max_len = max(max_len, i - seen[mask]);
            } else {
                seen[mask] = i;  // Store the first occurrence of this mask
            }
        }

        return max_len;
    }
};


