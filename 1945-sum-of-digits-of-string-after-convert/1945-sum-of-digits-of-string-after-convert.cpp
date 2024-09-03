#include <iostream>
#include <string>

class Solution {
public:
    int getLucky(std::string s, int k) {
        std::string numStr = "";
        
      
        for (char c : s) {
            int num = c - 'a' + 1;
            numStr += std::to_string(num);
        }
        
       
        while (k > 0) {
            int sum = 0;
            for (char c : numStr) {
                sum += c - '0';
            }
            numStr = std::to_string(sum);
            k--;
        }
        
        
        return std::stoi(numStr);
    }
};


