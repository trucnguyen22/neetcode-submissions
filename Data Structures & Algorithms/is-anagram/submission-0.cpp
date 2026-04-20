class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1. choose map to store frequency
        // 2. loop through 2 string
        // 3. loop through the map again to check all values are 0

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> myMap;

        for (int i = 0; i < s.length(); i++) {
            char curr_char = s[i];
            myMap[curr_char]++;
        }

        for (int i = 0; i < t.length(); i++) {
            char curr_char = t[i];
            myMap[curr_char]--;
        }

        for (const auto& pair : myMap) {
            if (pair.second > 0) {
                return false;
            }
        }
        return true;
    }
};
