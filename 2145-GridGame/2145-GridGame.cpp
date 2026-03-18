// Last updated: 3/18/2026, 2:23:18 PM
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long bottomRowSum = 0;
        long long minSecondRobotPoints = LLONG_MAX;

        for (int col = 0; col < grid[0].size(); col++) {
            topRowSum -= grid[0][col];
            long long maxPoints = max(bottomRowSum, topRowSum);
            minSecondRobotPoints = min(minSecondRobotPoints, maxPoints);
            bottomRowSum += grid[1][col];
        }

        return minSecondRobotPoints;
    }
};
