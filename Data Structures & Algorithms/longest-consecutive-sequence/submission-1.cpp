class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        int max_cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            hashset.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hashset.find(nums[i] - 1) == hashset.end()) {
                int cnt = 1, j = 1;
                while (hashset.find(nums[i] + j) != hashset.end()) {
                    cnt++;
                    j++;
                }
                max_cnt = max(max_cnt, cnt);
            }
        }
        return max_cnt;
    }
};
