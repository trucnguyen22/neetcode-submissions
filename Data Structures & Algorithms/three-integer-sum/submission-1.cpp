class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> fre;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) fre[nums[i]]++;

        for (int i = 0; i < nums.size(); i++) {
            fre[nums[i]]--;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                fre[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                int target = -(nums[i] + nums[j]);
                if (fre[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
            }

            for (int j = i + 1; j < nums.size(); j++) fre[nums[j]]++;
        }

        return res;
    }
};
