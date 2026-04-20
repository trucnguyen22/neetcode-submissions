class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums = [1, 2, 4, 6]
        // 1 -> [..., ..., ..., ...]
        // 1, 2 -> [..., 1, ..., ...]
        // 1, 2, 4 -> [..., 1, 1 * 2, ...]
        // 1, 2, 4, 6 -> [..., 1, 1 * 2, 1 * 2 * 4]

        int product_so_far = 1;
        vector<int> output(nums.size(), 1);

        // go forward
        for (int i = 0; i < nums.size(); i++) {
            output[i] = product_so_far * output[i];
            product_so_far *= nums[i];
        }
        product_so_far = 1;

        // reverse
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] = product_so_far * output[i];
            product_so_far *= nums[i];
        }

        return output;
    }
};
