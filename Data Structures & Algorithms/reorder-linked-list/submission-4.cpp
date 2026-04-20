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
        
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode* half1 = head;
        ListNode* half2 = prev;
        while (half1 && half2) {
            ListNode* tmp1 = half1->next;
            ListNode* tmp2 = half2->next;

            half1->next = half2;
            half2->next = tmp1;

            half1 = tmp1;
            half2 = tmp2;
        }
    }
};
