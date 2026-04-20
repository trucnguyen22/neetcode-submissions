/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodemap;

    Node* copyRandomList(Node* head) {
        // First iteration can't solve the random pointer since we can't reach
        // to the node that haven't been seen.

        // The hashmap can solve for tracing back to node's random

        if (!head) {
            nodemap[nullptr] = nullptr;
            return nullptr;
        }

        Node* copy = new Node(head->val);
        nodemap[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = nodemap[head->random];

        return copy;
    }
};
