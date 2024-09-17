#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Combine both sentences
        string combined = s1 + " " + s2;
        
        // Create a map to count the occurrences of each word
        unordered_map<string, int> wordCount;
        stringstream ss(combined);
        string word;
        
        // Count each word's occurrence
        while (ss >> word) {
            wordCount[word]++;
        }
        
        // Find words that appear exactly once
        vector<string> result;
        for (const auto& pair : wordCount) {
            if (pair.second == 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};


