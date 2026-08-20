class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int res = 0;
        string res_str = "";
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = 1 ? (s[i] == s[j] && (j-i+1 <= 3 || dp[i+1][j-1] == 1)) : 0;
                if (dp[i][j] == 1 && j-i+1 > res) {
                    res = j-i+1;
                    res_str = s.substr(i, j-i+1);
                }
            }
        }

        return res_str;
    }
};
