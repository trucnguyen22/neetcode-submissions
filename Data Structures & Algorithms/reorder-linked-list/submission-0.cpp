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
        // 0 -> 1 -> 2 -> 3 -> 4
        // reorder: 0 4 1 3 2
        vector<ListNode*> list;
        ListNode* curr = head;

        while (curr) {
            list.push_back(curr);
            curr = curr->next;
        }

        int lo = 0, hi = list.size() - 1;
        while (lo <= hi) {
            if (lo == hi) {
                list[lo]->next = nullptr;
                return;
            }
            list[lo]->next = list[hi];
            lo++;
            
            if (lo == hi) {
                list[hi]->next = nullptr;
                return;
            }
            list[hi]->next = list[lo];
            hi--;
        }
    }
};
