class Solution {
public:
    bool isAnagram(string s, string t) {
        // case 1: inequality
        if (s.size() != t.size()) return 0;

        // case 2: checking frequency
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val) return 0;
        }
        return 1;
    }
};
