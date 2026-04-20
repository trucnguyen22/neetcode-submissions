class Solution {
public:
    int trap(vector<int>& height) {
        int totalvol = 0;
        int str = 0, end = height.size() - 1;
        int leftwall = height[str], rightwall = height[end];

        while (str < end) {
            if (leftwall < rightwall) {
                totalvol += leftwall - height[str];
                str++;
                leftwall = max(leftwall, height[str]);
            } else {
                totalvol += rightwall - height[end];
                end--;
                rightwall = max(rightwall, height[end]);
            }
        }

        return totalvol;
    }
};
