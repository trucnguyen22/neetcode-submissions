class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size()), suffix(height.size());
        int totalvol = 0;

        for (int i = 0; i < height.size(); i++) prefix[i] = (i == 0 ? height[i] : max(prefix[i-1], height[i]));
        for (int i = height.size()-1; i >= 0; i--) suffix[i] = (i == height.size()-1 ? height[i] : max(suffix[i+1], height[i]));

        for (int i = 0; i < height.size(); i++) {
            totalvol += min(prefix[i], suffix[i]) - height[i];
        } 

        return totalvol;
    }
};
