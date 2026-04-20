class Solution {
public:
    bool isPalindrome(string s) {
        int str_p = 0, end_p = s.length() - 1;
        while (str_p < end_p) {
            while (str_p < end_p && !isalnum(s[str_p])) str_p++;
            while (str_p < end_p && !isalnum(s[end_p])) end_p--;
            if (tolower(s[str_p]) != tolower(s[end_p])) {
                return false;
            }
            str_p++, end_p--;
        }
        return true;
    }
};
