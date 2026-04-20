class Solution {
public:

    string encode(vector<string>& strs) {
        string single_str = "";

        for (int i = 0; i < strs.size(); i++) {
            string number = to_string(strs[i].size());
            single_str += number + "#" + strs[i];
        }

        return single_str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int index = 0;

        // one cycle for decoding a string
        while (index < s.length()) {
            int str_size = 0;
            string curr_str = "";

            while (s[index] != '#') {
                str_size = str_size * 10 + (s[index] - '0');
                index++;
            }
            index++;

            while (str_size > 0) {
                curr_str += s[index];
                index++;
                str_size--;
            }

            strs.push_back(curr_str);
        }

        return strs;
    }
};
