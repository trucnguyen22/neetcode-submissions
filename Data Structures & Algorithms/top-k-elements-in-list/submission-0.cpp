class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step 1: convert to map (value, frequency)
        // step 2: sort
        // step 3: find the most k

        map<int, int> myMap;

        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]]++;
        }

        vector<pair<int, int>> sortedVec(myMap.begin(), myMap.end());

        sort(sortedVec.begin(), sortedVec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(sortedVec[i].first);
        }

        return ans;
    }
};
