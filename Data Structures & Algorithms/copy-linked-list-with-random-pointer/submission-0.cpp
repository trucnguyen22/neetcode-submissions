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
    Node* copyRandomList(Node* head) {
        // 3 7 4 5 null
        // 3
        // 3 7
        // 3 7 4
        // 3 7 4 5 
        // 3 7 4 5 null

        //  1   2 3 null
        // null 3 3 

        //  3   7 4 5 null
        // null 5 3 7

        if (!head) return nullptr;

        unordered_map<Node*, int> nodemap; // <Node*, idx>
        vector<Node*> nodes;

        // fisrt pass
        int idx = 0;
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            prev = new Node(curr->val);
            nodes.push_back(prev);
            nodemap[curr] = idx; idx++;
            curr = curr->next;
        }
        nodes.push_back(nullptr);

        // second pass
        idx = 0;
        curr = head;
        while (curr) {
            int point_to = -1;
            if (curr->random) {
                point_to = nodemap[curr->random];
                nodes[idx]->random = nodes[point_to]; 
            } else nodes[idx]->random = nullptr;
            nodes[idx]->next = nodes[idx + 1]; idx++;
            curr = curr->next;
        }

        // // final pass
        // for (int i = 0; i < nodes.size(); i++) {
        //     int point_to = nodemap[nodes[i]].second;
        //     if (point_to == -1) nodes[i]->random = nullptr;
        //     else nodes[i]->random = nodes[point_to];
        // }

        return nodes[0];
    }
};
