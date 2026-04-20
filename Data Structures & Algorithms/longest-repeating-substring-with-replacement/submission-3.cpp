class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end());
        int res = 0;

        for (char c : charSet) {
            int max_count = 0, count = 0, l = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) count++;
                max_count = max(max_count, count);

                while ((r - l + 1) - max_count > k) {
                    if (s[l] == c) count--;
                    l++;
                }

                res = max(res, (r - l + 1));
            }
        }

        return res;
    }
};
