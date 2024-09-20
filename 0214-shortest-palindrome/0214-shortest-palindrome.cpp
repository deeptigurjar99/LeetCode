#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;

        // Compute KMP table (lps array)
        int n = new_s.size();
        vector<int> lps(n, 0);
        
        // Build the KMP table (longest prefix which is also a suffix)
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                ++j;
            }
            lps[i] = j;
        }

        // The part of the string to be added is the non-palindromic suffix of rev_s
        int to_add_len = s.size() - lps[n - 1];
        return rev_s.substr(0, to_add_len) + s;
    }
};

