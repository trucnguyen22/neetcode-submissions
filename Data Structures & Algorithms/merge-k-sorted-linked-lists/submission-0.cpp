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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // iterate to k linked-lists

        ListNode *smallest = nullptr;
        ListNode *newhead = nullptr, *pre = nullptr;
        // bool iteration = 0;

        while (true) {
            for (ListNode*& head : lists) {
                if (!head) continue;
                if (!smallest) smallest = head;
                else {
                    if (head->val < smallest->val) {
                        smallest = head;
                    }
                }
            }
            if (!smallest) break;
            ListNode *curr = new ListNode(smallest->val);
            if (!newhead) newhead = curr;
            if (pre) pre->next = curr;
            pre = curr;

            for (ListNode*& head : lists) {
                if (head == smallest) {
                    head = head->next;
                    break;
                }
            }
            smallest = nullptr;
        }

        return newhead;
    }
};
