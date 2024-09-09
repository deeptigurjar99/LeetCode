#include <vector>
using namespace std;



class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1)); // Initialize matrix with -1

        // Spiral traversal boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        // Pointer to traverse the linked list
        ListNode* current = head;

        // Spiral filling
        while (top <= bottom && left <= right && current) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right && current; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;  // Move top boundary down

            // Traverse from top to bottom down the right column
            for (int i = top; i <= bottom && current; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;  // Move right boundary left

            // Traverse from right to left across the bottom row
            for (int i = right; i >= left && current; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;  // Move bottom boundary up

            // Traverse from bottom to top up the left column
            for (int i = bottom; i >= top && current; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;  // Move left boundary right
        }

        return matrix;
    }
};
