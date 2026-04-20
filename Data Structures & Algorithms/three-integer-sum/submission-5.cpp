class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int str = i + 1, end = nums.size() - 1;
            while (str < end) {
                while (str > i + 1 && nums[str] == nums[str-1]) str++;
                while (end < nums.size() - 1 && nums[end] == nums[end+1]) end--;

                if (str >= end) break;
                
                int curr = nums[str] + nums[end]; 
                if (curr == target) {
                    res.push_back({nums[i], nums[str], nums[end]});
                    str++, end--;
                } else if (curr > target) end--;
                else str++;
            }
        }

        return res;
    }
};
