class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Hint 1: brute force
        // Hint 2: we will have (m + n) / 2 elements to the left of the median
        // Thinking: try to find the lowerbound in nums2 of the current pos in nums1
        //           then adjust the bound to find the actual median pos

        // 0 1 
        // 0 1 2

        if (nums1.size() < nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size(), median = (m + n - 1) / 2;
        int lo = 0, hi = nums1.size() - 1, x;
        double ans = 0.0;

        while (lo <= hi) {
            x = (lo + hi) / 2;
            int rest = median - x - 1;
            if (rest == -1) {
                if ((m + n) % 2 == 1) return nums1[x];
                else if (x == m - 1) return (double(nums1[x] + nums2[0])) / 2;
                else return (double(nums1[x] + nums1[x + 1])) / 2; 
            }
            if (rest < n && nums2[rest] <= nums1[x + 1]) {
                if ((m + n) % 2 == 1) ans = double(max(nums1[x], nums2[rest]));
                else if (rest == n - 1) ans = (double(max(nums1[x], nums2[rest])) + double(nums1[x + 1])) / 2;
                else ans = (double(max(nums1[x], nums2[rest])) + double(min(nums1[x + 1], nums2[rest + 1]))) / 2; 
                hi = x - 1;
            } else {
                lo = x + 1;
            }
        }

        return ans;
    }

    int findLowerbound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        int pos = -1;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] <= target) {
                pos = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return pos;
    }
}; 
