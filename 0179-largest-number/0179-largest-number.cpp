#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert each number to string
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom comparator to sort the numbers
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // Edge case: if the largest number is "0", return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Concatenate all the sorted numbers
        string result;
        for (const string &s : strNums) {
            result += s;
        }

        return result;
    }
};


