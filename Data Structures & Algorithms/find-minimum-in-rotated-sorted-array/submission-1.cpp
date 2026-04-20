class Solution {
public:
    int findMin(vector<int> &nums) {
        // Hint 1
        // Hint 2
        // Hint 3
        return search(nums, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int lo, int hi) {
        if (hi - lo == 1) {
            return min(nums[lo], nums[hi]);
        }
        int mid = (lo + hi) / 2;
        if (nums[lo] > nums[mid]) {
            search(nums, lo, mid);
        } else if (nums[mid] > nums[hi]){
            search(nums, mid, hi);
        } else {
            return nums[lo];
        }
    }
};
