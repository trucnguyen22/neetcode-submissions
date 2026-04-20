class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> dict;
    Node *head;
    Node *tail;

    void remove(Node *node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }

    void insert(Node *node) {
        if (tail) tail->next = node;
        else head = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dict.clear();
        head = tail = nullptr;
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end()) return -1;
        Node *node = dict[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) remove(dict[key]);

        Node *new_node = new Node(key, value);
        insert(new_node);

        dict[key] = new_node;

        // remove if full
        if (dict.size() > capacity) {
            Node *node = head;
            dict.erase(node->key);
            remove(node);
            delete node;
        }
    }
};
