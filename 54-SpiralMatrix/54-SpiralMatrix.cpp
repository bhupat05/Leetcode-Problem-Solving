// Last updated: 3/18/2026, 3:02:20 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        vector<int> res;

        while(top <= bottom && left <= right) {
            // top row
            for(int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;

            // right column
            for(int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }

            // left column
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
};
