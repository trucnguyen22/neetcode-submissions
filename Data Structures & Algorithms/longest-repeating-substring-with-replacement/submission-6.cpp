class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> cnt;
            int maxf = 0;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j]]++;
                maxf = max(maxf, cnt[s[j]]);
                
                if ((j - i + 1) - maxf <= k) {
                    res = max(res, (j - i + 1));
                } else break;
            }
        }

        return res;
    }
};
