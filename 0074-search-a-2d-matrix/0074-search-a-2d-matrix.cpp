class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = 0, c = 0;
            r = mid / matrix[0].size();
            c = mid % matrix[0].size();

            if (matrix[r][c] < target) {
                left = mid + 1;
            } else if (matrix[r][c] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};