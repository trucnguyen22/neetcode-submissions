class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int size = n * 2;
        vector<string> output;
        for (int r = 1; r < size; r += 2) {
            vector<string> middle = subgenerate(1, r - 1);
            vector<string> right = subgenerate(r + 1, size - 1);
            string curr;
            if (middle.empty()) {
                curr = "()";
                if (right.empty()) output.push_back(curr);
                for (int j = 0; j < right.size(); j++) {
                    output.push_back(curr + right[j]);
                }
            }
            for (int i = 0; i < middle.size(); i++) {
                curr = "(" + middle[i] + ")";
                if (right.empty()) output.push_back(curr);
                for (int j = 0; j < right.size(); j++) {
                    output.push_back(curr + right[j]);
                }
                curr = "";
            }
        }

        return output;
    }

    vector<string> subgenerate(int l, int r) {
        // [(]...()...[)]
        //  1 ........ 5
        
        // checking bound
        if (r <= l) return vector<string>();
        
        vector<string> subs;

        for (int i = l + 1; i <= r; i += 2) {
            vector<string> middle = subgenerate(l + 1, i - 1);
            vector<string> right = subgenerate(i + 1, r);
            string curr = "";
            if (middle.empty()) {
                curr = "()";
                if (right.empty()) subs.push_back(curr);
                for (int j = 0; j < right.size(); j++) {
                    subs.push_back(curr + right[j]);
                }
            }
            for (int j = 0; j < middle.size(); j++) {
                curr = "(" + middle[j] + ")";
                if (right.empty()) subs.push_back(curr);
                for (int k = 0; k < right.size(); k++) {
                    subs.push_back(curr + right[k]);
                }
                curr = "";
            }
        }
        
        return subs;
    }
};
