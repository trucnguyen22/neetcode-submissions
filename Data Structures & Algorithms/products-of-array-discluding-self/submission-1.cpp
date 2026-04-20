class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // idea: output[i] = prefix[i-1] * suffix[i+1]
        
        vector<int> prefix(nums.size(), 1), suffix(nums.size(), 1), output(nums.size());

        for (int i = 0; i < nums.size(); i++) prefix[i] = (i == 0 ? nums[i] : prefix[i-1] * nums[i]);
        for (int i = nums.size() - 1; i >= 0; i--) suffix[i] = (i == (nums.size() - 1) ? nums[i] : suffix[i+1] * nums[i]);

        output[0] = suffix[1];
        output[nums.size()-1] = prefix[nums.size()-2];
        for (int i = 1; i < nums.size()-1; i++) {
            output[i] = prefix[i-1] * suffix[i+1];
        }

        return output;
    }
};
