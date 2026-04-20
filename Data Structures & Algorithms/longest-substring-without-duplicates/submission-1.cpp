class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> idx; // <char, index>
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if (idx.find(s[r]) != idx.end()) {
                l = max(idx[s[r]] + 1, l);
            }
            idx[s[r]] = r;
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
