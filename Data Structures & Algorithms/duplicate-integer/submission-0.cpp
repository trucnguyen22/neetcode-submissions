class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> myMap;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (myMap[nums[i]] == 1) {
                return true;
            }
            myMap[nums[i]]++;
        }
        return false;
    }

};