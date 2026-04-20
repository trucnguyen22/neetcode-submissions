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
        unordered_set<ListNode*> exists;

        if (curr == nullptr) 
            return false;

        exists.insert(curr);
        while (curr->next) {
            if (exists.count(curr->next)) {
                return true;
            }
            curr = curr->next;
            exists.insert(curr);
        }

        return false;
    }
};
