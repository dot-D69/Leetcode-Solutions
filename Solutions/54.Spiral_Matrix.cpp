class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n  = matrix.size(); // no. of rows
        int m = matrix[0].size(); // no. of cols
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> res;

        while (top <= bottom && left <= right) {
            // Right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Down
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // Check if there are more rows to process
            if (top <= bottom) {
                // Left
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Check if there are more columns to process
            if (left <= right) {
                // Up
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        //  return the result vector
        return res;
    }
};
