class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // idea: for i, nums[i] + (target - nums[i]) = target. So checking if (target - nums[i]) 
        // is nums[j] for i != j or not

        unordered_map<int, int> diff; // nums, index

        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            if (diff.find(value) != diff.end()) {
                return {diff[value], i};
            }
            diff[nums[i]] = i;
        }

        // error
        return {};
    }
};
