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
        // iterate to k linked-lists to find the smallest
        // end when all lists[i] are nullptr

        ListNode *head = new ListNode();
        ListNode *curr = head;

        while (true) {
            int min = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) continue;
                if (min == -1 || lists[i]->val < lists[min]->val) min = i;
            }

            if (min == -1) break;
            ListNode *node = new ListNode(lists[min]->val);
            curr->next = node;
            lists[min] = lists[min]->next;
            curr = curr->next;
        }

        return head->next;
    }
};
