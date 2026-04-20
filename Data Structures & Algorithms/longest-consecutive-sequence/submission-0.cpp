class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // nums     = [2, 20, 4, 10, 3, 4, 5]
        // hashset -> [2, 3, 4, 5, 10, 20]
        // 2, 3, 4, 5,
        // 20,
        // 4

        // convert to hashset
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); i++) {
            hashset.insert(nums[i]);
        }

        // find the longest consecutive sequence
        int longest_length = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hashset.count(nums[i] - 1)) {
                continue;
            }
            int curr_length = 1;
            int next = nums[i] + 1;
            while(hashset.count(next)) {
                curr_length++;
                next++;
            }
            longest_length = max(longest_length, curr_length);
        }
        return longest_length;
    }
};
