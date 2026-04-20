class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Hint 1: brute force
        // Hint 2: we will have half = (m + n) / 2 elements to the left of the median
        // Thinking: if we select x elements in nums1, then we'd select half-x elements in nums2 
        //           that divides into 2 groups
        //           compare the max value in selected group with the min value of the rest group

        // 0 1 
        // 0 1 2
        // 0 1 2 3 4

        if (nums1.size() < nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size(), median = (m + n - 1) / 2;
        int lo = 0, hi = m - 1;
        double ans = 0.0;

        while (lo <= hi) {
            int x1 = (lo + hi) / 2; // x1, x2 are nums1, nums2 pointers, respectively
            int x2 = median - x1 - 1;
            if (x2 <= -1 || nums2[x2] <= nums1[x1 + 1]) {
                if (x2 <= -1) {
                    if ((m + n) % 2 == 1) return double(nums1[x1]);
                    if (nums2.empty())
                        return double(nums1[x1] + nums1[x1 + 1]) / 2;
                    return double(nums1[x1] + ((x1 + 1 == m) ? nums2[0] : min(nums1[x1 + 1], nums2[0]))) / 2;
                }
                else if (x2 == n - 1) {
                    if ((m + n) % 2 == 1) return double(max(nums1[x1], nums2[x2]));
                    return double(max(nums1[x1], nums2[x2]) + nums1[x1 + 1]) / 2;
                }
                else {
                    if ((m + n) % 2 == 1) ans = double(max(nums1[x1], nums2[x2]));
                    else ans = double(max(nums1[x1], nums2[x2]) + min(nums1[x1 + 1], nums2[x2 + 1])) / 2;
                }
                hi = x1 - 1;
            } else {
                lo = x1 + 1;
            }
        }

        return ans;
    }
}; 
