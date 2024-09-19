#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        // Iterate through the expression and check for operators
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Recursively solve the left and right sub-expressions
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine the results from left and right based on the current operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        // If the expression is purely numeric (no operators), convert it to an integer
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};

