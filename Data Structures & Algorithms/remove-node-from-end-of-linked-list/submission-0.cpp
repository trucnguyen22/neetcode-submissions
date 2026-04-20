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
        int size = 0;
        ListNode* curr = head;

        while (curr) {
            curr = curr->next;
            size++;
        }

        int rmv_pos = size - n;
        int idx = 0;

        ListNode* prev = nullptr;
        ListNode* newhead = nullptr;
        curr = head;
        // 0 1 2
        while (curr) {
            ListNode* tmp = curr->next;
            if (idx == rmv_pos) {
                curr->next = nullptr;
                if (prev) prev->next = tmp;
            } else {
                prev = curr;
            }
            if (!newhead) newhead = prev;
            curr = tmp;
            idx++;
        }

        return newhead;
    }
};
