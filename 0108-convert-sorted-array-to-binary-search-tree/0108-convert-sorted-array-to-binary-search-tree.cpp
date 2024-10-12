#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // Helper function to convert a portion of the array to a BST
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        // Choose the middle element to ensure balance
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
