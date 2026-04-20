class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        // [-1, -1, 0, 1, 2, 4]
        for (int i = 0; i < nums.size(); i++) {
            // remove duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // remove duplicates
                    while (nums[left] == nums[left - 1]) left++;
                    while (nums[right] == nums[right + 1]) right--;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};
