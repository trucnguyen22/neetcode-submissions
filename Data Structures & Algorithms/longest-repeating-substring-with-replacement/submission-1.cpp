class Solution {
public:
    int characterReplacement(string s, int k) {
        // 1. 26 english char
        // 2. [x, y, y, x]
        // [x] -> [1]
        // [x, y] -> [2, 1]
        // [x, y, y] -> [(3, 0), (3, 1)]
        // [x, y, y, x] -> [(4, 0), (4, 0)]
        // [x, y, y, x, y] -> [(4, 0), (5, 0)]

        // [z, e, f, g, z, a, a, a, b, z, z]
        // [z]
        // [z, e]
        // [z, e, f]
        //    [e, f, g]
        //       [f, g, z]
        //          [g, z, a]
        // ...
        //                [a, a, a, b, z]

        unordered_map<char, int> fre;
        int l = 0;
        int max_seq = 0;
        int max_fre = 0;

        for (int i = 0; i < s.length(); i++) {
            fre[s[i]]++;
            max_fre = max(max_fre, fre[s[i]]);

            while ((i - l + 1) - max_fre > k) {
                fre[s[l]]--;
                l++;
            }

            max_seq = max(max_seq, (i - l + 1));
        }

        return max_seq;
    }
};
