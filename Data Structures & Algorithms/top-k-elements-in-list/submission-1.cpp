class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        vector<vector<int>> buckets(nums.size() + 1);

        for (int num : nums) {
            fre[num]++;
        }

        for (const auto& pair : fre) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> res;
        
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }

        // error
        return {};
    }
};
