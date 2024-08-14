class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end of nums1 and nums2
        int i = m - 1; // Last element of the m part of nums1
        int j = n - 1; // Last element of nums2
        int k = m + n - 1; // Last position of nums1 where we will place the largest element

        // While there are elements in both arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 is still left
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to check for nums1, as the remaining elements are already in place
    }
};
