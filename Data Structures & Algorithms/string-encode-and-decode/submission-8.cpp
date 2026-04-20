class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_str = "";
        for (int i = 0; i < strs.size(); i++) {
            encode_str += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encode_str;
    }

    vector<string> decode(string s) {
        vector<string> decode_strs;
        int stat_cnt = 1; // 0 for size part, 1 for actual str
        int cnt = 0;
        string curr_decode_str = "";
        for (int i = 0; i < s.size(); i++) {
            if (stat_cnt) {
                if (s[i] == '#') {
                    stat_cnt = 0;
                    continue;
                }
                cnt = cnt * 10 + (s[i] - '0');
            } else {
                if (!cnt) {
                    stat_cnt = 1;
                    decode_strs.push_back(curr_decode_str);
                    i--;
                    continue;
                }
                cnt--;
                curr_decode_str += s[i];
                if (!cnt) {
                    stat_cnt = 1;
                    decode_strs.push_back(curr_decode_str);
                    curr_decode_str = "";
                }
            }
        }
        if (!stat_cnt) decode_strs.push_back(curr_decode_str);
        return decode_strs;
    }
};
