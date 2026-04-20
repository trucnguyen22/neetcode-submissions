class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> fre;

        for (int i = 0; i < n; i++) {
            fre.insert(nums[i]);
        }
        
        return !(fre.size() == n);
    }
};