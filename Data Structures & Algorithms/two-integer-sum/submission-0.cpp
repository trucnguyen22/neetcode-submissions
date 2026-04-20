class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force O(n^2)
        // O(n)
        // step 1. initialize memory
        // 
        // [2, 3], target = 5
        // 2 -> ...
        // 3 -> ... -> [0, 1]
        //
        // [..., 2, 1, 3], target = 4, find = 2
        // 2 -> ... find 2
        // 1 -> ... find 3
        // 3 -> ... find 1 
        //
        // step 2. use memory
        // [], 2
        // [2], 1
        // [2, 1], 3

        unordered_map<int, pair<int, bool>> myMap; // (value, <index, exists>)
        
        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]].first = -1;
            myMap[nums[i]].second = true;
        }

        for (int i = 0; i < nums.size(); i++) {
            int seek_value = target - nums[i];
            if (myMap[seek_value].first != -1 && myMap[seek_value].second == true) {
                return {myMap[seek_value].first, i};
            }
            myMap[nums[i]].first = i;
        }

        return {0, 0};
    }
};
