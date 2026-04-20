class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> myMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        int lo = 0, hi = myMap[key].size() - 1, mid;
        string target = "";

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (myMap[key][mid].first <= timestamp) {
                target = myMap[key][mid].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return target;
    }
};
