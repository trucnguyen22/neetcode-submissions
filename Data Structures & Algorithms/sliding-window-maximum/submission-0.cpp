class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // [1, 2, 1, 0, 4, 2, 6], k = 3
        // [1, 2, 1], queue = [2, 1, 1]
        //    [2, 1, 0], queue = [2, 1, 1, 0]
        //       [1, 0, 4], queue = [4, 1, 1, 0]

        // defined the pair<value, index> e
        struct greater_pair {
            bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            } 
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater_pair> pq;
        vector<int> maxs_in_window;
        int l = 0;

        // first window setup
        for (int r = 0; r < k; r++) {
            pq.push({nums[r], r});
        }
        maxs_in_window.push_back(pq.top().first);

        // all windows processing
        for (int r = k; r < nums.size(); r++) {
            pq.push({nums[r], r});
            l++;
            while (pq.top().second < l) {
                pq.pop();
            }

            maxs_in_window.push_back(pq.top().first);
        }

        return maxs_in_window;
    }
};
