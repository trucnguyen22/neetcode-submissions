class Solution {
public:
    bool isValid(string s) {
        // "[()]"
        stack<char> opens;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                opens.push(s[i]);
            } else {
                if (opens.empty()) {
                    return false;
                }
                if (s[i] == ']' && opens.top() != '[' || s[i] == '}' && opens.top() != '{' || s[i] == ')' && opens.top() != '(') {
                    return false;
                } else {
                    opens.pop();
                }
            }
        }
        if (!opens.empty()) {
            return false;
        }
        return true;
    }
};
