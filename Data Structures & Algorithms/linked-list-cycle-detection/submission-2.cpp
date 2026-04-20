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

         if (curr == nullptr) 
            return false;
         
         while (curr->next) {
            if (curr->next->val == -1)
                return true;
            curr->val = -1;
            curr = curr->next;
         }

         return false;
    }
};
