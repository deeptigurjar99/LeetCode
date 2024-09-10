#include <algorithm> // for std::gcd
using namespace std;


class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, return the head as it is.
            return head;
        }

        ListNode* curr = head;
        
        while (curr && curr->next) {
            // Calculate the GCD of the current node's value and the next node's value.
            int gcdValue = __gcd(curr->val, curr->next->val);
            
            // Create a new node with the GCD value.
            ListNode* gcdNode = new ListNode(gcdValue);
            
            // Insert the new node between curr and curr->next.
            gcdNode->next = curr->next;
            curr->next = gcdNode;
            
            // Move to the next pair (skip the newly inserted node).
            curr = gcdNode->next;
        }
        
        return head;
    }
};
