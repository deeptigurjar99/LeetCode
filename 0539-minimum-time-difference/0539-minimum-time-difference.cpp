#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<int> minutes;
        
        // Convert each time in "HH:MM" format to minutes since 00:00
        for (const std::string& time : timePoints) {
            int hours = std::stoi(time.substr(0, 2));
            int mins = std::stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the minutes
        std::sort(minutes.begin(), minutes.end());
        
        // Calculate the minimum difference between adjacent times
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = std::min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Handle the circular case (difference between last and first time across midnight)
        int circularDiff = 1440 - (minutes.back() - minutes.front());
        minDiff = std::min(minDiff, circularDiff);
        
        return minDiff;
    }
};


