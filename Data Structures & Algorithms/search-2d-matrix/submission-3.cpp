class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int size = m * n;
        int lo = 0, hi = size - 1, mid;
        // [0, 1, 2]
        // [3, 4, 5]
        // [6, 7, 8]
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int row = mid / n;
            int col = mid - (row * n);
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false; 
    }
};
