class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 0 1 2 3
        // 3 3 1 1

        // 0 1 2 3 4
        // 1 2 3 2 2
        
        // 1. using 2 fast-slow pointers
        // 2. first loop to place the meet point
        // 3. second loop findout the start of the loop, which is the output

        int slow, fast;
        slow = fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int slow2 = 0;
        while (slow2 != slow) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
