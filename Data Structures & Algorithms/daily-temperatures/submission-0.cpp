class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 1. to get the first warmer than ith
        // 2. 
        int n = temperatures.size() - 1;
        vector<int> output;
        stack<pair<int, int>> warmer; // pair<value, index>

        for (int i = n; i >= 0; i--) {
            if (!warmer.empty()) {
                while (!warmer.empty() && warmer.top().first <= temperatures[i]) {
                    warmer.pop();
                }
            }
            warmer.empty() ? output.push_back(0) : output.push_back(warmer.top().second - i);
            warmer.push({temperatures[i], i});
        }

        vector<int> reverse_output;
        for (int i = output.size() - 1; i >= 0; i--) {
            reverse_output.push_back(output[i]);
        }

        return reverse_output;
    }
};
