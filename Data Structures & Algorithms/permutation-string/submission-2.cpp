class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // permuation = [a, b, c]
        // [l, e, c, a, b, e, e]

        int window_size = s1.length();
        int cap = window_size;
        unordered_map<char, int> fre;

        for (int i = 0; i < s1.length(); i++) {
            fre[s1[i]]++;
        }

        // fast check
        if (window_size > s2.length()) {
            return false;
        }

        int l = 0;
        for (int i = 0; i < window_size; i++) {
            fre[s2[i]]--;
            if (fre[s2[i]] >= 0) cap--;
            if (cap == 0) return true; 
        }
        // keep the left + 1, and right + 1
        for (int r = window_size; r < s2.length(); r++) {
            // keep the left + 1
            fre[s2[l]]++;
            if (fre[s2[l]] > 0) cap++; 
            l++;

            // keep the right + 1
            fre[s2[r]]--;
            if (fre[s2[r]] >= 0) cap--;
            
            if (cap == 0) return true;
        }

        return false;
    }
};
