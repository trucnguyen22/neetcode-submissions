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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* firstp = head;
        ListNode* secondp = head;
        int idx = 1;

        while (idx <= n) {
            secondp = secondp->next;
            idx++;
        }

        ListNode* prev = nullptr;
        while (secondp) {
            prev = firstp;
            firstp = firstp->next;
            secondp = secondp->next;
        }
        ListNode* tmp = firstp->next;
        firstp->next = nullptr;
        if (!prev) return tmp;
        prev->next = tmp;
        return head;
    }
};
