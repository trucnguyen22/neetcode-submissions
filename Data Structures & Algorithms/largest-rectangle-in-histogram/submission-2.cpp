class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> greater; // (index)
        int n = heights.size();
        int left[n]; // store left boundary
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            while (!greater.empty() && heights[greater.top()] >= heights[i]) {
                int height = heights[greater.top()];
                int width = i - left[greater.top()];
                max_area = max(max_area, (height * width));
                greater.pop();
            }

            if (greater.empty()) left[i] = 0;
            else left[i] = greater.top() + 1;

            greater.push(i);
        }

        // process the rest of stack
        while (!greater.empty()) {
            int height = heights[greater.top()];
            int width = n - left[greater.top()];
            max_area = max(max_area, (height * width));
            greater.pop();
        }
        return max_area;
    }
};
