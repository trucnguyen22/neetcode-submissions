class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [5, 6, 7, 1, 2, 3, 4]
        int lo = 0, hi = nums.size() - 1, mid;
        bool cannotfind = true;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            if ((nums[lo] <= target && target <= nums[mid]) || 
                (nums[lo] > nums[mid] && ((nums[lo] <= target && target >= nums[mid]) || 
                                            (nums[lo] >= target && target <= nums[mid])))) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (cannotfind) return -1;
        return 0;
    }
};
