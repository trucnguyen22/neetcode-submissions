class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fre_s, fre_t;

        if (s.size() != t.size()) return 0;
        for (int i = 0; i < s.size(); i++) {
            fre_s[s[i]]++;
            fre_t[t[i]]++;
        }

        return fre_s == fre_t;
    }
};
