/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* curr = head;
        ListNode* fast_pointer = curr;
        ListNode* slow_pointer = curr;

        while (fast_pointer && fast_pointer->next) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
             
            if (slow_pointer == fast_pointer) 
                return true;
        }

        return false;
    }
};
