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
        set<char> unique_char;

        for (int i = 0; i < s.length(); i++) {
            unique_char.insert(s[i]);
        }

        int most_fre = 0;
        for (char c : unique_char) {
            int cost = 0;
            int left = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != c) {
                    while (cost == k) {
                        if (s[left] != c) {
                            cost--;
                        }
                        left++;
                    }
                    cost++;
                }
                most_fre = max(most_fre, i - left + 1);
            }
        }
        
        return most_fre;
    }
};
