#include <vector>
#include <unordered_set>


class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        // Step 1: Store the values in nums in an unordered_set for fast lookup
        std::unordered_set<int> valuesToRemove(nums.begin(), nums.end());
        
        // Step 2: Use a dummy node to simplify edge cases (e.g., head removal)
        ListNode* dummy = new ListNode(0);  // Dummy node
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* current = head;
        
        // Step 3: Traverse the linked list
        while (current != nullptr) {
            if (valuesToRemove.count(current->val)) {
                // If the current node's value is in the set, remove it by adjusting the prev pointer
                prev->next = current->next;
            } else {
                // Otherwise, move the prev pointer to the current node
                prev = current;
            }
            current = current->next;  // Move to the next node
        }
        
        // Step 4: Return the new head (which is dummy->next)
        return dummy->next;
    }
};
