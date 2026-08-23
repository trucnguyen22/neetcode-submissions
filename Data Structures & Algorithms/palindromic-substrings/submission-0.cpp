class Solution {
public:
    int countSubstrings(string s) {
        // abc
        // a, ab, abc, b, bc, c
        // c, b, bc, a, ab, abc
        // a, b, ba, 

        int cnt = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                    cnt += 1;
                }
            }
        }

        return cnt;
    }
};
