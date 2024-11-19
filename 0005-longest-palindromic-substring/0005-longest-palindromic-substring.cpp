class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;
        
        int start = 0, maxLen = 1;

        // Function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the palindrome
            return right - left - 1;
        };
        
        for (int i = 0; i < n; ++i) {
            // Try expanding around i (odd-length palindrome)
            int len1 = expandAroundCenter(i, i);
            // Try expanding around i and i+1 (even-length palindrome)
            int len2 = expandAroundCenter(i, i + 1);
            
            // Find the longer of the two palindromes
            int len = max(len1, len2);
            
            // If this palindrome is the longest one so far, update start and maxLen
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};
