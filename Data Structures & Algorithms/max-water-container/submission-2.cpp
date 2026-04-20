class Solution {
public:
    int maxArea(vector<int>& heights) {
        int str = 0, end = heights.size() - 1;
        int maxvol = 0, curr = 0;
        while (str < end) {
            curr = min(heights[str], heights[end]) * (end - str);
            maxvol = max(maxvol, curr);
            if (heights[str] < heights[end]) str++;
            else end--;
        }

        return maxvol;
    }
};