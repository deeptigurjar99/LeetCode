#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int i = 0, j = 0;
        
        // Merge strings in alternating order
        while (i < word1.length() && j < word2.length()) {
            mergedString += word1[i++];
            mergedString += word2[j++];
        }
        
        // Append remaining characters from word1, if any
        while (i < word1.length()) {
            mergedString += word1[i++];
        }
        
        // Append remaining characters from word2, if any
        while (j < word2.length()) {
            mergedString += word2[j++];
        }
        
        return mergedString;
    }
};


