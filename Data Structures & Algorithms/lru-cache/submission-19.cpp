class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> dict;
    list<int> used; // list of used keys
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void makefront(list<int>::iterator e, int key) {
        if (e != used.end()) used.erase(e);
        used.push_back(key);
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end()) return -1;
        makefront(dict[key].second, key);
        return dict[key].first;
    }
    
    void put(int key, int value) {
        // update if needed
        if (dict.find(key) != dict.end()) {
            makefront(dict[key].second, key);
        } else {
            makefront(used.end(), key);
        }

        dict[key].first = value;
        dict[key].second = --used.end();

        // full
        if (dict.size() > capacity) {
            int least_recently_used = used.front(); // key
            used.pop_front();
            dict.erase(least_recently_used);
        }
    }
};
