class Solution {
public:
    string minWindow(string s, string t) {
        // s = "ZODYXAZV"
        // s1 = "ZYXZ"
        // Z
        // Z Y
        // Z Y X
        // Y X Y
        // Y X Y Z
        // X Y Z
        // t = "XYZ"

        // fast check
        if (s.length() < t.length()) return "";

        unordered_map<char, int> fre;
        int cap = t.length();

        for (int i = 0; i < t.length(); i++) {
            fre[t[i]]++;
        }

        // only take char that are in string t
        vector<pair<char, int>> valid_char;
        for (int i = 0; i < s.length(); i++) {
            if (fre[s[i]] > 0) valid_char.push_back({s[i], i});
        } 

        int l = 0;
        pair<int, int> shortest = {0, s.length() + 1};
        for (int r = 0; r < valid_char.size(); r++) {
            fre[valid_char[r].first]--;
            if (fre[valid_char[r].first] >= 0) {
                cap--;
            }

            // YZZXY
            while (cap == 0) {
                if (shortest.second - shortest.first > valid_char[r].second - valid_char[l].second) {
                    shortest.second = valid_char[r].second;
                    shortest.first = valid_char[l].second;
                }
                fre[valid_char[l].first]++;
                if (fre[valid_char[l].first] > 0) cap++;
                l++;
            }
        }

        if (shortest.second == s.length() + 1) return "";
        return s.substr(shortest.first, shortest.second - shortest.first + 1);
    }
};
