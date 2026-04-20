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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1 2 3
        // 4 5 6
        // 5 7 9

        // 1 2 3
        // 9 9

        ListNode *head = nullptr, *pre = nullptr; 
        int remember = 0;
        while (l1 || l2) {
            int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + remember;
            if (val > 9) {
                remember = 1;
                val %= 10;
            } else remember = 0;

            if (!head) {
                head = new ListNode(val);
                pre = head;
            } else {
                pre->next = new ListNode(val);
                pre = pre->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (remember) pre->next = new ListNode(remember);

        return head;
    }


};
