class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // algorithm: counting bits of the target integer
        //            since the target integer's bits are highest
        //            so if that bit counting in 'nums' is higher than in the normal range, we use that bit
        //            finally, we got all bits of the target.
        // 1. log2(10000) ~= 14
        // 2. checking at the position b from 0 to 13

        int res = 0, n = nums.size();
        for (int i = 0; i < 13; i++) {
            int mask = 1 << i, count_in_num = 0, count_in_range = 0;

            for (int num : nums) {
                if (num & mask) ++count_in_num;
            }

            for (int num = 1; num < n; num++) {
                if (num & mask) ++count_in_range;
            }

            if (count_in_num > count_in_range) res |= mask;
        }

        return res;
    }
};
