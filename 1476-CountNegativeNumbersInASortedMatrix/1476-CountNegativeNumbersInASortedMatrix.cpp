// Last updated: 3/18/2026, 2:24:41 PM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int r = 0;
        int c = cols - 1;
        int cnt = 0;

        while(r < rows && c >= 0) {
            if(grid[r][c] < 0) {
                cnt += (rows - r);
                c--;
            } else {
                r++;
            }
        }
        return cnt;
    }
};