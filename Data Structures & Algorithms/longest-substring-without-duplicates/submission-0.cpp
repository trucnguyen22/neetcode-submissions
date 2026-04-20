class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // s = "zxyzxyz"
        // z
        // zx
        // zxy
        // .xyz
        // ..yzx

        // s = "abczzabcde"

        unordered_map<char, int> sequence_map;
        int left = 0;
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (sequence_map[s[i]] > 0) {
                while(s[left] != s[i]) {
                    sequence_map[s[left]] = 0;
                    left++;
                }
                left++;
                continue;
            }
            sequence_map[s[i]]++;
            max_len = max(max_len, i - left + 1);
        }

        return max_len;
    }
};
