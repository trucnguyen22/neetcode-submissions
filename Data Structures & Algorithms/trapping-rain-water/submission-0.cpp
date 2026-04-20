class Solution {
public:
    int trap(vector<int>& height) {
        // [0, 4, 1, 3, 2]
        // 1. try to find the greatest left and right
        // at the position[i]
        // 2. using prefix and suffix

        int n = height.size();
        int prefix[n];
        int suffix[n];

        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(prefix[i], suffix[i]) - height[i];
        }

        return water;
    }
};
 