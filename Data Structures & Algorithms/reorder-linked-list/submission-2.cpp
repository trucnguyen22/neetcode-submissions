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
    void reorderList(ListNode* head) {
        // Hint 1: avoid using extra space
        // Hint 2: split into two halves and reverse the second one
        //         [1, 2, 3, 4, 5]
        //      -> [1, 2]
        //      -> [5, 4, 3]

        if (!head || !(head->next)) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        // 0 1
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half1 = head;
        ListNode* half2 = reverselist(slow->next);
        slow->next = nullptr;
        ListNode* reorder = head;

        while (reorder) {
            ListNode* tmp1 = half1->next;
            ListNode* tmp2 = half2->next;

            reorder->next = half2;
            reorder = reorder->next;
            reorder->next = tmp1;
            reorder = reorder->next;
            if (!tmp2) return;

            half1 = tmp1;
            half2 = tmp2;
        }
    }

    ListNode* reverselist(ListNode* head) {
        // 0 1 2
        if (!head) return nullptr;
        
        ListNode* newhead = head;
        if (head->next) {
            newhead = reverselist(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newhead;
    }
};
